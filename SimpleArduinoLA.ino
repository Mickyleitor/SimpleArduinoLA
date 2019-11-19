#define NUM_CANALES 16
#define PIN_CLK 2
#define PIN_SHOOT 3
#define ZOOM 10
#define SEPARADOR 2
#define NUM_SAMPLES 500

// Buffer de datos, probamos con una longitud del doble las muestras (Debido al diseño puede producir algún que otro OOM)
uint16_t MUESTRA = 0;
uint8_t canal,aux=0;

void setup() {
  // Configuramos puerto lo más rápido posible
  Serial.begin(115200);
  // Configuramos todos los canales que queramos analizar como entradas analogicas
  for (canal=0;canal<NUM_CANALES;canal++){
    pinMode(A0+canal,INPUT);
  }
  // Configuramos PIN que sera nuestro CLK
  pinMode(PIN_CLK,OUTPUT);
  // Configuramos PIN para detener/proseguir con captura de samples
  pinMode(PIN_SHOOT,INPUT_PULLUP);
} 
void loop(){
  // Solo entramos si tenemos orden de recoger muestras
  if(digitalRead(PIN_SHOOT) == LOW){
    for(int sample = 0; sample < NUM_SAMPLES/ZOOM ; sample++){
      // Cambiamos de NIVEL el CLK
      digitalWrite(PIN_CLK,!(digitalRead(PIN_CLK)));
      // Recogemos ZOOM samples seguidos
      // En la practica esto será nuestro zoom en el Serial Plotter
      for(aux=0;aux<ZOOM;aux++) {
        // Creamos una variable msg
        // Para enviar todo directamente de un mensaje por el serial
        String msg;
        // Mediante manipulacion directa de los puertos recogemos un sample
        // de todos los canales analogicos
        MUESTRA = (PINK << 8 ) | PINF;
        // construimos el mensaje analizando cada pin de los puertos
        for(canal=0;canal<NUM_CANALES;canal++){
          msg.concat((((MUESTRA >> canal) & 1 ))+(canal*SEPARADOR));
          msg.concat(',');
        }
        // Enviamos el mensaje
        Serial.println(msg);
        // Esperamos que se envie
        Serial.flush();
      }
    }
  }
}
