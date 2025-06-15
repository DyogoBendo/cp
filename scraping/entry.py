from typing import List
from utils import get_now

from enum import Enum

MEMBERS_LIST = ["Dyogo", "Davi", "Mandelli"]
MAIN_USER = "Dyogo"

def print_members_list():
    print("Members list: ", end="")
    for i in range(len(MEMBERS_LIST)):
        print(f"{MEMBERS_LIST[i]}({i})", end=" ")
    print("\n")

class CompetitionType(Enum):
    GYM = "Gym"
    CONTEST = "Contest"
    VIRTUAL_CONTEST = "Virtual Contest"

class ProblemType(Enum):
    GYM_LIVE = 0
    GYM_UPSOLVING = 1
    GYM_EXTRA = 2
    CONTEST = 3
    UPSOLVING = 4
    USACO = 5
    MARATONA = 6
    VIRTUAL_CONTEST = 7

class QuestionSpreadsheetProblemType(Enum):
    USACO = "USACO"
    CONTEST = "Contest"
    UPSOLVING = "Upsolving"
    MARATONA = "Maratona"
    GYM = "Gym"

class ChampionshipSpreadsheetEntryType(Enum):
    GYM_QUESTION = "Questão Gym"
    THEME_CP = "ThemeCP"
    LIVE_CONTEST = "Live Contest"
    GYM = "Gym"
    UPSOLVING = "Upsolving"
    UPSOLVING_GYM= "Upsolving Gym"
    TOPIC_QUESTION = "Questão Tópico"
    QUESTION = "Questão"
    CONTEST_QUESTION = "Questão Contest"

class EntryType(Enum):
    GYM = "gym"
    CONTEST = "contest"
    PROBLEM = "problem"

class Problem:
    DIFFICULTY_NAME = [
        "Trivial",
        "Fácil", 
        "Médio",
        "Médio",
        "Difícil",
        "Insano"
    ]
    type: ProblemType
    name: str
    date: str
    origin: str
    solve_it = bool
    got_it: bool   
    who_solve: str 
    link: str
    time: int
    wa: int
    contest_name: str
    difficulty: int
    
    
    def __init__(self, type: ProblemType = None, name: str = None, date: str = None, origin: str = None, who_solve: str = None, link: str=None, time: int = None, wa: int = None, contest_name: str = None):
        print(f"problem: {name}")
        self.name = name        
        self.link = link
        self.origin = origin
        
        self.date = date if date is not None else get_now()        
        self.type = type if type is not None else self.get_type()
        self.who_solve = who_solve if who_solve is not None else self.get_who_solve()
        self.solve_it = True if self.who_solve == MAIN_USER else False
        
        if self.type in [ProblemType.GYM_LIVE, ProblemType.CONTEST, ProblemType.VIRTUAL_CONTEST]:            
            self.time = time
            if(self.who_solve == MAIN_USER):
                self.got_it = True
            else:
                self.got_it = False                
        else:
            self.got_it = self.get_got_it()
            self.time = self.get_time()
                    
        self.wa = wa
        self.contest_name = contest_name 
        self.difficulty = self.get_difficulty() if self.who_solve == MAIN_USER else None
        print()        
    
    def get_type(self):
        options = str.join("\n", [ f"{problem_type.name}({problem_type.value})" for problem_type in ProblemType])
        print(options)
        ans = int(input(f"What is the kind of this problem? "))    
        return ProblemType(ans)       
    
    def get_solve_it(self):
        solve_it=  input(f"Solve it? ")
        return solve_it == "1" 
    
    def get_got_it(self):
        solve_it=  input(f"Got it? ")
        return solve_it == "1"       
    
    def get_time(self):
        return int(input("time in minutes to solve: "))
    
    def get_who_solve(self):
        return MEMBERS_LIST[int(input(f"Who solve? "))]
    
    def get_difficulty(self):
        return int(input("Pick difficulty[0, 5]: "))
    
    def __str__(self):
        return (
            f"Problem(name='{self.name}', "
            f"type='{self.type.name}', "
            f"date='{self.date}', "
            f"origin='{self.origin}', "
            f"who_solve='{self.who_solve}', "
            f"got_it={self.got_it}, "
            f"solve_it={self.solve_it}, "
            f"time={self.time}, "
            f"wa={self.wa}, "
            f"link='{self.link}')"
        )
        
    def to_question_spreadsheet(self):
        spreadsheet_problem_type = None
        if self.type == ProblemType.GYM_LIVE:
            spreadsheet_problem_type = QuestionSpreadsheetProblemType.GYM
        elif self.type in [ProblemType.CONTEST, ProblemType.VIRTUAL_CONTEST]:
            spreadsheet_problem_type = QuestionSpreadsheetProblemType.CONTEST
        elif self.type in [ProblemType.GYM_EXTRA, ProblemType.UPSOLVING, ProblemType.GYM_UPSOLVING]:
            spreadsheet_problem_type = QuestionSpreadsheetProblemType.UPSOLVING
        elif self.type == ProblemType.USACO:
            spreadsheet_problem_type = QuestionSpreadsheetProblemType.USACO    
        elif self.type == ProblemType.MARATONA:
            spreadsheet_problem_type = QuestionSpreadsheetProblemType.MARATONA
        return [self.name, self.link, self.date, spreadsheet_problem_type.value, self.origin, self.got_it, self.solve_it, self.time, self.DIFFICULTY_NAME[self.difficulty]]
    
    def to_competition_question_spreadsheet(self):        
        difficulty_info = self.DIFFICULTY_NAME[self.difficulty] if self.difficulty != None else None
        return [self.name, self.contest_name, self.date, self.got_it, self.who_solve, self.time, self.wa, difficulty_info]
    
    def to_championship_spreadsheet(self):
        entry_type = ChampionshipSpreadsheetEntryType.QUESTION
        
        if self.type in [ProblemType.GYM_LIVE, ProblemType.GYM_UPSOLVING, ProblemType.MARATONA]:
            entry_type = ChampionshipSpreadsheetEntryType.GYM_QUESTION
            
        elif self.type == ProblemType.CONTEST:
            entry_type = ChampionshipSpreadsheetEntryType.CONTEST_QUESTION
            
        elif self.type == ProblemType.USACO:
            entry_type = ChampionshipSpreadsheetEntryType.TOPIC_QUESTION
            
        elif self.type == ProblemType.GYM_EXTRA:
            entry_type = ChampionshipSpreadsheetEntryType.UPSOLVING_GYM
            
        elif self.type == ProblemType.UPSOLVING:
            entry_type = ChampionshipSpreadsheetEntryType.UPSOLVING
            
        return [self.who_solve, entry_type.value, self.date, self.name, self.difficulty, self.time, self.link]

class Competition:
    name: str
    date: str
    questions_numbers: int
    solved_problems_qtd: int
    position: int
    problems: List[Problem]
    members: List[str]
    type: CompetitionType
    solved_problems: List[Problem]
    link: str    
    difficulty: int
    time: int

    def __init__(self, name: str, date: str, problems: List[Problem], solved_problems: List[Problem], position: int, members: List[str], type: CompetitionType, link: str, difficulty: int, time: int):
        self.name = name
        self.date = date
        self.problems_qtd = len(problems)
        self.solved_problems_qtd = len(solved_problems)
        self.problems = problems
        self.position = position
        self.members = members
        self.type = type
        self.solved_problems = solved_problems
        self.link = link
        self.difficulty = difficulty
        self.time = time
        
    def __str__(self):
        problems_str = ', '.join([problem.name for problem in self.problems])
        solved_problems_str = ', '.join([problem.name for problem in self.solved_problems])
        members_str = ', '.join(self.members)
        
        return (
            f"Competition(name='{self.name}', "
            f"type='{self.type.name}', "
            f"date='{self.date}', "
            f"position={self.position}, "
            f"members=[{members_str}], "
            f"problems_qtd={self.problems_qtd}, "
            f"solved_problems_qtd={self.solved_problems_qtd}, "
            f"problems=[{problems_str}], "
            f"solved_problems=[{solved_problems_str}])"
        )
    
    def to_competition_spreadsheet(self):
        return [self.name, self.type.value, self.date, str.join(", ", self.members), f"{self.solved_problems_qtd}/{self.problems_qtd}", self.position, self.link]

    def to_championship_spreadsheet(self):
        if(self.type != CompetitionType.VIRTUAL_CONTEST):
            entry_type = ChampionshipSpreadsheetEntryType.GYM if self.type == CompetitionType.GYM else ChampionshipSpreadsheetEntryType.LIVE_CONTEST
            return [MAIN_USER, entry_type.value, self.date, self.name, self.difficulty, self.time, self.link]