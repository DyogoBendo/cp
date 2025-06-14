from datetime import datetime

def get_now()->str:
    return format_date(datetime.now())

def format_date(date: datetime)->str:
    return date.strftime("%d-%m-%Y")