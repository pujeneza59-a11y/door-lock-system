# Door Lock System

An automated home security project built using an **Arduino Uno**, simulated completely inside **Proteus**.

## Components Used
* Arduino Uno
* 4x3 Matrix Keypad
* Servo Motor (Lock Mechanism)
* 16x2 LCD Display

## How to Run
1. Open the `.pdsprj` file in Proteus.
2. Open the `.ino` file in the Arduino IDE and compile it to get your local `.hex` file.
3. Double-click the Arduino board inside Proteus and link your fresh `.hex` file.
4. Press Play to run the simulation.

## How the System Works

This project uses sequential logic to handle passcode verification, visual feedback, and physical access control. 

### 1. Hardware Integration
* **4x3 Matrix Keypad:** Used by the user to input the secret passcode.
* **16x2 LCD Display:** Displays real-time status messages (e.g., "sequency booting","Enter Pin", "cprrect pin", "Wrong Password","press * to tray again")
* **Servo Motor:** Acts as the physical deadbolt lock mechanism. It rotates to 180 degrees to unlock and returns to 0 degrees to lock.

### 2. Software Logic Sequence
1. **Idle State:** The LCD displays "Enter Password" and the Servo is at 0 degrees (Locked).
2. **User Input:** As the user presses keys on the Keypad, characters are stored in an array buffer, and the LCD prints asterisks (`*`) to hide the passcode.
3. **Password Verification:** 
   * When the user submits the password, the code compares the input buffer to a predefined master password string (e.g., `1234`).
4. **correct pin:** If the password matches, the LCD prints "correct pin!", the Servo rotates to 180 degrees to unlock the door, and then re-locks automatically after a few seconds.
5. **incorrect pin:** If the password does not match, the LCD displays "Wrong Password!", the Servo remains locked, and the system resets.
6. **press * to try again:**to try if the submited passcode is worng
