FROM balenalib/raspberry-pi-python

WORKDIR /app
COPY . /app

#RUN curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py && sh get-pip.py
RUN apt-get update && apt-get install python3-gpiozero

CMD ["python", "/app/app.py"]