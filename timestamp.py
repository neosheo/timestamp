from datetime import datetime
import json
import os

# set path to last_run.json
working_dir = os.path.dirname(__file__)
path = f'{working_dir}\\last_run.json'

''' check to see if last_run.json exists
    if it does exist print the last time
    the script was run, if it doesn't exist
    create the file'''
if os.path.exists(path):
    with open(path, 'r') as file:
        data = json.load(file)
        print(f'Last run on {data["last_run"]}')
else:
    open(path, 'w').close()

# get date and time
date = str(datetime.now())
month = [0]
day = [0]
year = [0]
hour = [0]

def parseDate():
    if int(date[5:7]) < 10:
        month[0] = date[6:7]
    elif int(date[5:7]) >= 10:
        month[0] = date[5:7]
    if int(date[8:10]) < 10:
        day[0] = date[9:10]
    elif int(date[8:10]) >= 10:
        day[0] = date[8:10]
    year[0] = date[:4]
    if int(date[11:13]) < 10:
        hour[0] = date[12:13]
    elif int(date[11:13]) >= 10:
        hour[0] = date[11:13]

parseDate()

timestamp = f'{month[0]}/{day[0]}/{year[0]} {hour[0]}:{date[14:16]}'
timestamp_dict = {"last_run":timestamp}

# write date to last_run.json
with open(path, 'w') as file:
    json.dump(timestamp_dict, file)
