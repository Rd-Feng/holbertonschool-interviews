#!/usr/bin/python3
"""fetch all todos grouped by users
"""
import requests
import json

res = {}
users = requests.get('https://jsonplaceholder.typicode.com/users').json()
for u in users:
    todos = requests.get(
        'https://jsonplaceholder.typicode.com/todos?userId={}'.format(u['id'])
    ).json()
    res[u['id']] = [{
        'username': u['username'],
        'task': todo['title'],
        'completed': todo['completed']
    } for todo in todos]
with open('todo_all_employees.json', 'w') as f:
        json.dump(res, f)
