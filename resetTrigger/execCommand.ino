//Function to process messages from the serial port.
//input -> input message from serial port (excluding closing ';')
//Uses furst character in String as command
//All further additions are seen as 'values' (optional additional arguments)

void execCommand( String input )
{
  //List of possible command.
  String command = input.substring( 0, 1 );
  int value = (input.substring( 1, input.length() )).toInt();


  //Turn LED on
  if( command == "L" ){
    digitalWrite(ledPin, HIGH);
  }

  //Turn LED off
  else if( command == "l" ){
    digitalWrite(ledPin, LOW);
  }

  //Reset the controller at resetTriggerPin
  //Gives LOW signal for 50ms, HIGH again after.
  else if( command == "r" ){
    //Reset controller at resetTriggerPin (connected via 1k Ohm resistor.
    digitalWrite(resetTriggerPin, LOW);
    delay(50);
    digitalWrite(resetTriggerPin, HIGH);
  }

  //Ping (return number from 'value')
  else if( command == "p" ){
    //Ping
    //Print 'value' to serial
    Serial.println( value );
  }
}
