# coding:utf-8

from flask import Flask,render_template,request,redirect,url_for
from werkzeug.utils import secure_filename
import os

"""
    The module is about provider.
"""
# -*-encode:utf-8-*-
import sys

from flask import Flask, render_template, session,  request, abort, send_from_directory, make_response
import datetime
import os

from pymongo import MongoClient
import datetime
import json
import requests

app = Flask(__name__, template_folder="./", static_folder='../')
app.secret_key = os.urandom(24)
app.permanent_session_lifetime = datetime.timedelta(hours=5)

@app.route('/')
def test():
    return 'Connect success.'


@app.route('/<path:path>')
def send_js(path):
    return send_from_directory('../', path)


@app.route('/upload', methods=['POST', 'GET'])
def upload():
    if request.method == 'POST':
        f = request.files['file']
        basepath = os.path.dirname(__file__)  # 当前文件所在路径
        upload_path = os.path.join(basepath, '../',secure_filename(f.filename))  #注意：没有的文件夹一定要先创建，不然会提示没有该路径
        f.save(upload_path)
        return redirect(url_for('upload'))
    return render_template('upload.html')

if __name__ == '__main__':
    app.run(debug=True)