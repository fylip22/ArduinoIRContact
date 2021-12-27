// Module relais couplé à un détecteur infrarouge (PIR)
int PIRval = 0;
int PIRCx;
int PIRSens;
int RelaisCx;
int DureeAllum;

void setup() {
    // affectation des valeurs de base
  Serial.begin(9600);       // activation du moniteur série pour les tests 
  PIRCx=A0;                 // port analogique 0 pour le signal détecté par la sonde PIR
  PIRSens=500;              // sensibilité de la sonde PIR
  RelaisCx=13;              // port digital 13 pour le relais
  DureeAllum=10000 ;        // durée de fermeture du relais (ici allumage guirlande)
  pinMode(RelaisCx,OUTPUT); // indique que le connecteur est de type sortie
}

    // boucle principale du programme
void loop() {
  digitalWrite(RelaisCx,LOW);    // relais ouvert
  PIRval = analogRead(PIRCx);    // lecture de valeur de PIR
  Serial.println (PIRval);       // écriture de la valeur lue sur le moniteur série
  if (PIRval > PIRSens) {        // test de déclenchement
    digitalWrite(RelaisCx,HIGH); // fermeture du relais
    delay(DureeAllum);           // attente en milliseconde
  }
  }
