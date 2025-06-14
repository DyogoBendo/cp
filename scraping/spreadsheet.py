import os.path

from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

# If modifying these scopes, delete the file token.json.
SCOPES = ["https://www.googleapis.com/auth/spreadsheets"]

# The ID and range of a sample spreadsheet.
DIARIO_SPREADSHEET_ID = "1hcPRM8ku5m7KbdX-cGojkvmjccED1x-UBxeaQBOJaYU"
CHAMPIONSHIP_SPREADSHEET_ID = "1XmVD8u6HBHyKsT4M74b0w3dM9VvEWGAsDTcxRAsLYBQ"

CHAMPIONSHIP = "Entradas"
DIARIO_QUESTIONS = "questões"
DIARIO_COMPETITIONS_QUESTIONS = "questões competições"
DIARIO_COMPETITIONS = "resultados competições"

CHAMPIONSHIP_RANGE="A:H"
DIARIO_QUESTIONS_RANGE = "A:N"
DIARIO_COMPETITIONS_QUESTIONS_RANGE= "A:J"
DIARIO_COMPETITIONS_RANGE="A:H"

def insert_spreadsheet(values, spreadsheet_name, spreadsheet_id):
  """Shows basic usage of the Sheets API.
  Prints values from a sample spreadsheet.
  """
  creds = None
  # The file token.json stores the user's access and refresh tokens, and is
  # created automatically when the authorization flow completes for the first
  # time.
  if os.path.exists("token.json"):
    creds = Credentials.from_authorized_user_file("token.json", SCOPES)
  # If there are no (valid) credentials available, let the user log in.
  if not creds or not creds.valid:
    if creds and creds.expired and creds.refresh_token:
      creds.refresh(Request())
    else:
      flow = InstalledAppFlow.from_client_secrets_file(
          "credentials.json", SCOPES
      )
      creds = flow.run_local_server(port=0)
    # Save the credentials for the next run
    with open("token.json", "w") as token:
      token.write(creds.to_json())

  try:
    service = build("sheets", "v4", credentials=creds)

    body = {
        "values": values
    }

    range = f"{spreadsheet_name}!A1"    
    result = (
        service.spreadsheets().values()
        .append(
            spreadsheetId=spreadsheet_id,
            range=range,  # Target range
            valueInputOption="RAW",
            body=body
        )
        .execute()
    )

    print(f"{result.get('updates').get('updatedCells')} cells appended.")
  except HttpError as err:
    print(err)
