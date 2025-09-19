Requerimientos
==============

A la empresa Informa2, llega un cliente que dispone de un mensaje original en texto plano que ha sido
sometido a un proceso de compresión y posteriormente a un proceso de encriptación.

1. Compresión: El mensaje fue comprimido utilizando RLE o LZ78.
2. Encriptación: Una vez comprimido, el mensaje resultante fue encriptado mediante la aplicación de dos operaciones consecutivas:
   - Una rotación a la izquierda de cada byte en una cantidad n de bits (siendo 0 < n < 8).
   - Una operación XOR con una clave de un solo byte K.

El resultado de estas transformaciones es el mensaje comprimido y encriptado, que es el único
disponible.

Sin embargo, se conoce un fragmento del mensaje original en texto plano. Este fragmento servirá como
pista para determinar:

● ¿Qué método de compresión se utilizó (RLE o LZ78)?
● El valor de la rotación de bits n.
● El valor de la clave K usada en la operación XOR.

A partir del mensaje comprimido y encriptado, y del fragmento conocido del mensaje original, usted
deberá diseñar e implementar un programa que sea capaz de:

1. [20%] Identificar el método de compresión utilizado y los parámetros de encriptación (n y K).
2. [20%] Desencriptar el mensaje aplicando las operaciones inversas en el orden correcto.
3. [60%] Descomprimir el mensaje para obtener el texto original completo.

Para lograr lo anterior, se debe realizar la implementación propia de los algoritmos de compresión y
descompresión RLE y LZ78. De igual forma, deberá implementar los métodos de encriptación y
desencriptación con rotación de bits + XOR.

## Entradas
● Cadena que contiene el mensaje comprimido y encriptado.
● Fragmento conocido del mensaje original (texto plano).}

**Nota:** El texto incluye únicamente los caracteres de la A a la Z (mayúsculas y minúsculas) sin: tildes,
signos de puntuación, espacios en blancos, ni la Ñ. Puede incluir los dígitos del 0 al 9.

## Salidas

● Mensaje original completo reconstruido.
● Método y parámetros utilizados en los procesos de compresión y encriptación
