from flask import Flask, request, render_template, render_template_string, redirect
import subprocess
import urllib
flag = open('flag.txt').read()
app = Flask(__name__)
@app.route('/')
def main():
	if request.headers.get('User-Agent') != 'n00bz-4dm1n':
		print(request.headers.get)
		return render_template('incorrect_user_agent.html')
	if request.headers.get('Accept') != 'fl4g':
		return render_template('incorrect_accept.html')
	if request.headers.get('Connection') != 's3cur3':
		return render_template('incorrect_connection.html')
	if request.headers.get('Referer') != 's3cr3t.n00bz-4dm1n.xyz':
		return render_template('incorrect_referer.html')
	if request.headers.get('Give-Flag') != '7ru3':
		return render_template('incorrect_give_flag.html')
	return flag

if __name__ == '__main__':
	app.run(host='0.0.0.0', port=31401)