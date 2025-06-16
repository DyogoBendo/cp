import sys
from entry import Problem, Competition, CompetitionType
from codeforces import Codeforces
import spreadsheet

if __name__ == "__main__":   
    while True: 
        url = input("Link: ")
        cf = Codeforces(url)
        result = cf.get_data()
        if type(result) == Problem:     
            spreadsheet.insert_spreadsheet([result.to_question_spreadsheet()], spreadsheet.DIARIO_QUESTIONS, spreadsheet.DIARIO_SPREADSHEET_ID) 
            spreadsheet.insert_spreadsheet([result.to_championship_spreadsheet()], spreadsheet.CHAMPIONSHIP, spreadsheet.CHAMPIONSHIP_SPREADSHEET_ID) 
        elif type(result) == Competition:
            solved_questions = []
            championship = []
            competition_questions = []
            
            championship.append(result.to_championship_spreadsheet())
            for question in result.solved_problems:
                if question.who_solve == "Dyogo":
                    solved_questions.append(question.to_question_spreadsheet())
                    championship.append(question.to_championship_spreadsheet())                
            
            for question in result.problems:
                competition_questions.append(question.to_competition_question_spreadsheet())
            
            if result.type == CompetitionType.GYM:
                spreadsheet.insert_spreadsheet(competition_questions, spreadsheet.DIARIO_COMPETITIONS_QUESTIONS, spreadsheet.DIARIO_SPREADSHEET_ID) 
                
            spreadsheet.insert_spreadsheet([result.to_competition_spreadsheet()], spreadsheet.DIARIO_COMPETITIONS, spreadsheet.DIARIO_SPREADSHEET_ID) 
            spreadsheet.insert_spreadsheet(solved_questions, spreadsheet.DIARIO_QUESTIONS, spreadsheet.DIARIO_SPREADSHEET_ID) 
            spreadsheet.insert_spreadsheet(championship, spreadsheet.CHAMPIONSHIP, spreadsheet.CHAMPIONSHIP_SPREADSHEET_ID) 
            