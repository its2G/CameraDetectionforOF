# Import smtplib for the actual sending function
import smtplib

# Import the email modules we'll need
from email.message import EmailMessage


textfile = 'alert.txt'
with open(textfile, 'w') as fp:
    fp.write("Movement detected on cameras")

# Open the plain text file whose name is in textfile for reading.
with open(textfile) as fp:
    # Create a text/plain message
    msg = EmailMessage()
    msg.set_content(fp.read())

# me == the sender's email address
# you == the recipient's email address
msg['Subject'] = f'The contents of {textfile}'
msg['From'] = giovannidelboni@gmail.com       
msg['To'] =  giovannidelboni@gmail.com

# Send the message via our own SMTP server.
s = smtplib.SMTP('smtp.gmail.com', 587)
s.starttls()  # Secure the connection
s.login('giovannidelboni@gmail.com', 'giOzy2003')  # Login with your app password
s.send_message(msg)
s.quit()