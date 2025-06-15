import requests
from datetime import datetime
from entry import Problem, Competition, EntryType, ProblemType, CompetitionType, print_members_list

class Codeforces:
    url: str
    type: EntryType
    contest_id: str
    CODEFORCES_API_CONTEST_URL = "https://codeforces.com/api/contest.standings"
    MEMBERS_MAPPING = {
        "bielmandelli": "Mandelli",
        "daviedu": "Davi",
        "dyogobendo": "Dyogo"
    }
    ORIGIN = "Codeforces"
    
    def __init__(self, url: str):
        self.url = url
        self.type = self.extract_type()
        self.contest_id = self.extract_id()
    
    def extract_type(self) -> EntryType: 
        if(self.url.find("problem") != -1):
            return EntryType.PROBLEM
        if(self.url.find("gym") != -1):
            return EntryType.GYM
        return EntryType.CONTEST 
    
    def extract_id(self):
        return self.url.split("/")[4]
    
    def extract_problem_index(self):
        return ord(self.url.split("/")[-1]) - ord('A')
    
    def extract_members(self, members):
        members_names = []
        for member in members:
            members_names.append(self.MEMBERS_MAPPING[member["handle"]])
        return members_names
    
    def get_entry(self, data):
        contest = data["contest"]
        problems = data["problems"]
        contest_participation = data["rows"][0]
        rank = contest_participation["rank"]
        points = contest_participation["points"]            
        party = contest_participation["party"]
        members = party["members"]
        start_time = party.get("startTimeSeconds", 0)
        participant_type = party["participantType"]
        problem_results = contest_participation["problemResults"]
        members_names = self.extract_members(members)
        date = datetime.fromtimestamp(start_time).strftime("%d-%m-%Y")
                
        if self.type == EntryType.PROBLEM:
            problem_index = self.extract_problem_index()            
            cnt = 0
            name = ""
            for problem in problems:
                if problem_index == cnt:
                    name = problem["name"]
                                                    
                cnt += 1   
            
            return Problem(name=name, origin=self.ORIGIN, link=self.url, who_solve="Dyogo")
        else:
            if self.type == EntryType.GYM:
                print_members_list()
            
            problem_type = ProblemType.GYM_LIVE
            if self.type == EntryType.CONTEST:
                problem_type = ProblemType.VIRTUAL_CONTEST if participant_type == "VIRTUAL" else ProblemType.CONTEST                
            competition_type = CompetitionType.GYM if problem_type == ProblemType.GYM_LIVE else CompetitionType.CONTEST if problem_type == ProblemType.CONTEST else CompetitionType.VIRTUAL_CONTEST
    
            all_problems = []
            solved_problems = []
            for i in range(len(problems)):
                problem_info = problems[i]
                problem_result = problem_results[i]
                
                name= problem_info["name"]
                index = problem_info["index"]
                wa = None
                time = None
                points = int(problem_result["points"])                
                who_solve = "Ninguém"                
                if points > 0:                    
                    wa = problem_result["rejectedAttemptCount"]
                    time = int(problem_result["bestSubmissionTimeSeconds"]/60)                
                    who_solve = None if self.type == EntryType.GYM else "Dyogo"                    
                problem = Problem(name=name, type=problem_type, date=date, wa=wa, time=time, link=self.url + "/problem/"+index, origin=self.ORIGIN, who_solve=who_solve, contest_name=contest["name"])
                                
                all_problems.append(problem)
                if points > 0:                    
                    solved_problems.append(problem)                
            
            difficulty = contest.get("difficulty", 0)
            return Competition(name=contest["name"], date=date, problems=all_problems, solved_problems=solved_problems, members=members_names, position=rank, type= competition_type, link=self.url, difficulty=difficulty, time=contest["durationSeconds"]/60)
    
    def get_data(self):
        participant_types = "PRACTICE" if self.type == EntryType.PROBLEM else "CONTESTANT,VIRTUAL"                
        params = {
            "contestId": self.contest_id,
            "from": 1,
            "count": 1,
            "showUnofficial": True,
            "handles": "dyogobendo",
            "participantTypes": participant_types
        }                                
        response = requests.get(url=self.CODEFORCES_API_CONTEST_URL, params=params)    
        data = response.json()["result"]                                
        return self.get_entry(data)
        