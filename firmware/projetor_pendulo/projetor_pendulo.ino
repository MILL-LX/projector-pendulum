

#define POT_1_PIN A0
#define POT_2_PIN A1
#define DIR_2_PIN D2
#define PWM_2_PIN D3
#define DIR_1_PIN D4
#define PWM_1_PIN D5

const int min_pwm = 0;
const int max_pwm = 128;

void setup() {

	Serial.begin(115200);
	pinMode(POT_1_PIN, INPUT);
	pinMode(POT_2_PIN, INPUT);
	pinMode(DIR_2_PIN, OUTPUT);
	pinMode(PWM_2_PIN, OUTPUT);
	pinMode(DIR_1_PIN, OUTPUT);
	pinMode(PWM_1_PIN, OUTPUT);

	digitalWrite(DIR_1_PIN, HIGH);
	digitalWrite(DIR_2_PIN, HIGH);

}



void loop() {

	Serial.printf("%d\t%d\n", analogRead(POT_1_PIN), analogRead(POT_2_PIN));
	analogWrite(PWM_1_PIN,
		map(analogRead(POT_1_PIN), 0, 1023, min_pwm, max_pwm)
		);
	analogWrite(PWM_2_PIN,
		map(analogRead(POT_2_PIN), 0, 1023, min_pwm, max_pwm)
		);

	delay(100);

}