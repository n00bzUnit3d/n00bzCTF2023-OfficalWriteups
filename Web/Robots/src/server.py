#!/usr/bin/env python3
from flask import Flask, request, render_template, render_template_string, redirect
import urllib

app = Flask(__name__)

@app.route('/')
def main():
    return redirect('/robots')

@app.route('/robots')
def robots():
    return render_template_string(f'<p>Where the Robots at?</p>')
@app.route('/robots.txt')
def flag():
    return open('flag.txt').read()

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=36083)
