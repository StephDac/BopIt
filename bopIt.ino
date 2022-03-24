//Define Start pins
const int start = A1;

//Define Action pins
const int bopIt = A2;
const int slideIt = A3;
const int flipFlopIt = A4;

//Define score pins
const int scoreDigit0[4] = {1,2,3,4};
const int scoreDigit1[4] = {5,6,7,8};

//Define sound pins
const int sound = 9;

//Define light pins
const int successLight = 12;
const int failLight = 13;

//Variables to keep track of stuff during the program
bool success;
int randomNum;
long action;
int frequency;
int score;
const int duration = 5000;
int offset;
int pollTime;

//Function to update the score display digits
void updateScoreDisplay(const int scoreDigit[4], int remainder){
  for(int i = 3; i >= 0; i--){
    digitalWrite(scoreDigit[i], remainder % 2);
    remainder /= 2; 
    }
  }
  
void setup(){
	//Define Inputs
	pinMode(start, INPUT);
	
	pinMode(bopIt, INPUT);
	pinMode(slideIt, INPUT);
	pinMode(flipFlopIt, INPUT);
	
	//Define Outputs
	pinMode(scoreDigit0[0],OUTPUT);
	pinMode(scoreDigit0[1],OUTPUT);
	pinMode(scoreDigit0[2],OUTPUT);
	pinMode(scoreDigit0[3],OUTPUT);
	
	pinMode(scoreDigit1[0],OUTPUT);
	pinMode(scoreDigit1[1],OUTPUT);
	pinMode(scoreDigit1[2],OUTPUT);
	pinMode(scoreDigit1[3],OUTPUT);
	
	pinMode(sound,OUTPUT);
	
	randomSeed(analogRead(A0));
	}

void loop(){
	if(digitalRead(start) == HIGH){
		offset = 0;
		
		while (score < 99){
			success = false;
			
			//Pick Action
			randomNum = random(0,2);
			
			//Output sound
			switch(randomNum){
				//Bop-It
				case 0:
					frequency = 400;
					action = A2;
				break;
				//Slide-It
				case 1:
					frequency = 800;
					action = A3;
				break;
				//Flip-Flop-It
				case 2:
					frequency = 1600;
					action = A4;
				break;
				}
			tone(sound, frequency, 1000);
		
			//Poll sensor for a time
			pollTime = duration - offset;
			for(int i = 0; i < pollTime; i++){
				delay(1);
				if(digitalRead(action) == HIGH){
						success = true;
						break;
					}
				}
		
			//Display success/fail and increment score
			if(success == true){
				score++;
				digitalWrite(successLight, HIGH);
				delay(1000);
				digitalWrite(successLight, LOW);
				offset += 25;
				updateScoreDisplay(scoreDigit0, score % 10);
				updateScoreDisplay(scoreDigit1, score / 10);
			}else{
				digitalWrite(failLight, HIGH);
				delay(1000);
				digitalWrite(failLight, LOW);
				}
			
		
			}
		}
	
	}
