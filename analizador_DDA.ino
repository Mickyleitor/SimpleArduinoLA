#define NUM_CANALES 16
#define PIN_CLK 2
#define PIN_SHOOT 52
#define ZOOM 10
#define SEPARADOR 2
#define PIN_READ 7

// Buffer de datos, probamos con una longitud del doble las muestras (Debido al diseño puede producir algún que otro OOM)
uint16_t MUESTRA = 0;
uint8_t i,aux,clk=0;

void setup() {
  // Configuramos puerto lo más rápido posible
  Serial.begin(115200);
  // Configuramos todos los canales que queramos analizar como entradas analogicas
  for (i=0;i<NUM_CANALES;i++){
    pinMode(A0+i,INPUT);
  }
  // Configuramos PIN que sera nuestro CLK
  pinMode(PIN_CLK,OUTPUT);
  // Configuramos PIN para detener/proseguir con captura de samples
  pinMode(PIN_SHOOT,INPUT);
  // Configuramos PIN para DEBUG
  pinMode(PIN_READ,INPUT);
} 
void loop(){
  // Solo entramos si tenemos orden de recoger muestras
  if(digitalRead(PIN_SHOOT)>0.5){
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
      for(i=0;i<NUM_CANALES;i++){
        msg.concat((((MUESTRA >> i) & 1 ))+(i*SEPARADOR));
        msg.concat(',');
      }
      // Descomentar esto para utilizar el PIN_READ para debug
      // msg.concat(digitalRead(PIN_READ)+(16+NUM_CANALES));
      // Enviamos el mensaje
      Serial.println(msg);
      // Esperamos que se envie
      Serial.flush();
    }
  }
}
