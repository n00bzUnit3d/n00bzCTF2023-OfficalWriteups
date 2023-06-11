#!/usr/bin/env python3
from flask import *
import pathlib
import os
from werkzeug.utils import secure_filename

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/mypersonalsecrets/<file>")
def my_secrets(file = None):
    if file is None:
        return redirect(url_for("index"))
    return render_template(secure_filename(file))

@app.route("/upload", methods=['POST'])
def upload_secret():
    if "file" not in request.files:
        return redirect(url_for("index"))
    file = request.files['file']
    file_path = str(pathlib.Path(__file__).parent.resolve()) + "/uploads/" + file.filename
    print(file_path)

    if os.path.exists(file_path):
        return "Error"

    file.save(file_path)

    if not secure_file(file_path):
        os.remove(file_path)
        return "Stop trying to corrupt my server"
    
    return "Successfully uploaded"

@app.route('/posts/<name>')
def get_secret(name = None):
    file = str(pathlib.Path(__file__).parent.resolve()) + "/uploads/" + secure_filename(name)
    return read_secret(file)

def read_secret(path):

    file = open(path, 'r')
    data = file.read()
    file.close()

    return data

def secure_file(path):

    data = read_secret(path)

    if len(data) > 500:
        return False
    for ch in data:
        if not ch.isalnum() and not ch.isspace():
            print("this:" + str(ord(ch)))
            return False
    
    return True

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=1611)