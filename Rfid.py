class Rfid(object):

    def __init__(self):
        # Import
        import RPi.GPIO as GPIO
        import MFRC522
        import signal

        # Hook the SIGINT
        signal.signal(signal.SIGINT, end_read)

        # Create an object of the class MFRC522
        self.MIFAREReader = MFRC522.MFRC522()

    def loop(self):
        (status, TagType) = self.MIFAREReader.MFRC522_Request(
            self.MIFAREReader.PICC_REQIDL)

        # If a card is found
        if status == self.MIFAREReader.MI_OK:
            print "Card detected"

        # Get the UID of the card
        (status, uid) = self.MIFAREReader.MFRC522_Anticoll()

        # If we have the UID, continue
        if status == self.MIFAREReader.MI_OK:

            # Print UID
            print "Card read UID: " + str(uid[0]) + "," + str(uid[1]) + ","
            + str(uid[2]) + "," + str(uid[3])
