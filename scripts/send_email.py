import smtplib
from email.mime.text import MIMEText

def send_email(subject, body, to):
    msg = MIMEText(body)
    msg['Subject'] = subject
    msg['From'] = 'your_email@gmail.com'
    msg['To'] = to

    with smtplib.SMTP('smtp.gmail.com', 587) as server:
        server.starttls()
        server.login('your_email@gmail.com', 'your_password')
        server.send_message(msg)

if __name__ == "__main__":
    send_email("Motion Detected", "Motion has been detected by your camera.", "recipient_email@gmail.com")
