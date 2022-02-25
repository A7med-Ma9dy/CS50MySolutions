from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
app.config["TEMPLATES_AUTO_RELOAD"] = True
Session(app)

db = SQL("sqlite:///birthdays.db")

@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    shows = db.execute('SELECT * from birthdays;')
    return render_template("index.html", shows=shows)


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        db.execute('insert into birthdays(name) values(?)', session["name"])
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    session["name"] = None
    return redirect("/")