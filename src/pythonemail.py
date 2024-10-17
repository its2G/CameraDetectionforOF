import smtplib
from email.mime.text import MIMEText

print("This is a Python script running from openFrameworks!")

# Create an SMTP session
s = smtplib.SMTP('smtp.gmail.com', 587)

# Start TLS for security
s.starttls()

# Login using your email credentials
# Replace 'your_email@gmail.com' with the sender's email address
# Replace 'your_email_password' with the sender's email password (or App Password)
s.login("yowhatsmyg@gmail.com", "LeBlanc247")

# Create the message
message = "This is the email content you need to send."

# Define sender and receiver
sender_email = "yowhatsmyg@gmail.com"  # Replace with the sender's email address
receiver_email = "codingstuffonline@gmail.com"  # Replace with the recipient's email address

# Send the email
s.sendmail(sender_email, receiver_email, message)

# Terminate the session
s.quit()