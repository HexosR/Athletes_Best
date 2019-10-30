#define DEBUG wrong

//Long
long highscore;

//Bool
bool something = 1;

//Arrays Strings
String names[] = { "Swim time: ", "Bike time: ", "Run time: ", "Total time: " };
String disciplines[] = { "SWIM", "BIKE", "RUN" };
String times[] = { "seconds", "minutes", "hours" };

//Array
long total[4];

//Int
int x = 0;
int athlete_number = 0;
int best_one;

//Const
const int Minutes = 60;
const int Hours = 3600;

int MyFunction() {
	int seconds;
	while (!Serial.available());
	seconds = Serial.parseInt();
	return seconds;
}

void setup() {
#ifdef DEBUG 
	Serial.println("Something went wrong");
#endif
	Serial.begin(9600);
	while (something == 1) {
	begin:
		Serial.println("You want to add another athlete?");
		Serial.println("Write 1 if Yes");
		Serial.println("Write 0 if No");
		while (!Serial.available());
		int decision = Serial.parseInt();
		if (decision == 0) {
		here:
			Serial.print("The fastest athlete was no.");
			Serial.print(best_one);
			Serial.print(" with a total time of ");
			Serial.print(highscore / Hours);
			Serial.print("hr ");
			Serial.print(highscore % Hours / Minutes);
			Serial.print("min ");
			Serial.print(highscore % Minutes);
			Serial.println("sec ");
			goto begin;
		}
		else if (decision == 1) {
			athlete_number++;
			for (int a = 0; a <= 2; a++) {
				Serial.print("Please enter the number of hours for the ");
				Serial.println(disciplines[a]);
				total[a] = MyFunction() * Hours;
				if (disciplines[a] == "SWIM" && total[a] < 0) {
					Serial.println("You wrote a wrong value");
					goto here;
				}

				Serial.print("Please enter the number of minutes for the ");
				Serial.println(disciplines[a]);
				total[a] += MyFunction() * Minutes;

				Serial.print("Please enter the number of seconds for the ");
				Serial.println(disciplines[a]);
				total[a] += MyFunction();
			}
		}
		total[3] = total[0] + total[1] + total[2];

		if (x == 0 && (highscore < total[3])) {
			highscore = total[3];
			best_one = athlete_number;
			x = 1;
		}
		if ((x == 1) && (highscore > total[3])) {
			highscore = total[3];
			best_one = athlete_number;
		}
		for (int b = 0; b <= 3; b++) {
			Serial.print(names[b]);
			Serial.print(total[b] / Hours);
			Serial.print("hr ");
			Serial.print(total[b] % Hours / Minutes);
			Serial.print("min ");
			Serial.print(total[b] % Minutes);
			Serial.println("sec ");
		}
		Serial.println();
	}
}
void loop() {
}