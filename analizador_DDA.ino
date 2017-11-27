#define NUM_CANALES 16
#define CLK_FREQ 50
#define PIN_CLK 3
#define PIN_CLK_MUESTREO 2
#define PIN_SHOOT 52
#define SEPARADOR 2
#define ALARGADOR 50
#define NUM_MUESTRAS 500 / ALARGADOR

// Buffer de datos, probamos con una longitud del doble las muestras (Debido al diseño puede producir algún que otro OOM)
uint16_t MUESTRAS [2*NUM_MUESTRAS];
// Variables auxiliares
int8_t i,aux,pos;
// Variable que indica el la cantidad de muestras que se han recogido.
int NONRDY=0;

// Funcion que guarda en buffer el estado de los puertos K y F
// Se utiliza manipulación directa de puertos por que solo necesita una instrucción de CPU
// Y otra para sumar el NONRDY
void get_data(){
  MUESTRAS [NONRDY++] = (PINK << 8 ) | PINF;
}

// Imprime por pantalla todo el buffer con la ponderación adecuada para offset en analizador
void print_data(){
  for(aux=0;aux<NUM_MUESTRAS;aux++){
    for(pos=0;pos<ALARGADOR;pos++){
      for(i=0;i<NUM_CANALES;i++){
        Serial.print((((MUESTRAS[aux] >> i) & 1 ))+(i*SEPARADOR));
        Serial.print(",");
      }
    Serial.println();
    }
  }
}

void setup() {
  // Configuramos puerto lo más rápido posible
  Serial.begin(115200);
  // Configuramos todos los canales que queramos analizar como entradas analogicas
  for (i=0;i<NUM_CANALES;i++){
    pinMode(A0+i,INPUT);
  }
  pinMode(PIN_SHOOT,INPUT);
  // Generamos PWM en puerto deseado con frecuencia determinada
  tone(PIN_CLK,CLK_FREQ);
  // Enganchamos ISR en el pin que tengamos para escuchar el circuito (yo he puesto el mismo que el CLK)
  attachInterrupt(digitalPinToInterrupt(PIN_CLK_MUESTREO), get_data, CHANGE);
} 
void loop(){
  if(NONRDY>=NUM_MUESTRAS){
      // Si se ha llenado el buffer, quitar ISR
      detachInterrupt(digitalPinToInterrupt(PIN_CLK_MUESTREO));
      // El usuario decide mostrar ultimo paquete disponible?
      if(digitalRead(PIN_SHOOT)){
        // Imprimir datos
        print_data();
        // Reiniciar datos
        NONRDY=0;
      }
      // Enganchamos ISR de nuevo y esperamos
      attachInterrupt(digitalPinToInterrupt(PIN_CLK_MUESTREO), get_data, CHANGE);
  }
}



