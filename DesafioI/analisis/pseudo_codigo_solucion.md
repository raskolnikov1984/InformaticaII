# Pseudocódigo - Reconstrucción de Mensaje

Este documento describe el algoritmo y las funciones necesarias para resolver el problema de **reconstruir el mensaje original** a partir de un mensaje comprimido y encriptado.

---

## ALGORITMO ReconstruirMensaje
**ENTRADA:** mensaje_encriptado, fragmento_original  
**SALIDA:** mensaje_original, metodo_compresion, n, K  

---

**PASO 1:** Buscar parámetros de desencriptación correctos
**PARA** n **DESDE** 1 **HASTA** 7 **HACER**  
&nbsp;&nbsp;**PARA** K **DESDE** 0 **HASTA** 255 **HACER**  
&nbsp;&nbsp;&nbsp;&nbsp;mensaje_posible ← Desencriptar(mensaje_encriptado, n, K)  

&nbsp;&nbsp;&nbsp;&nbsp;**PASO 2:** Probar descompresión con RLE  
&nbsp;&nbsp;&nbsp;&nbsp;mensaje_rle ← DescomprimirRLE(mensaje_posible)  
&nbsp;&nbsp;&nbsp;&nbsp;**SI** fragmento_original **ES SUBCADENA DE** mensaje_rle **ENTONCES**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;metodo_compresion ← "RLE"  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mensaje_original ← mensaje_rle  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**RETORNAR** (mensaje_original, metodo_compresion, n, K)  
&nbsp;&nbsp;&nbsp;&nbsp;**FIN SI**  

&nbsp;&nbsp;&nbsp;&nbsp;**PASO 3:** Probar descompresión con LZ78  
&nbsp;&nbsp;&nbsp;&nbsp;mensaje_lz ← DescomprimirLZ78(mensaje_posible)  
&nbsp;&nbsp;&nbsp;&nbsp;**SI** fragmento_original **ES SUBCADENA DE** mensaje_lz **ENTONCES**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;metodo_compresion ← "LZ78"  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mensaje_original ← mensaje_lz  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**RETORNAR** (mensaje_original, metodo_compresion, n, K)  
&nbsp;&nbsp;&nbsp;&nbsp;**FIN SI**  

&nbsp;&nbsp;**FIN PARA**  
**FIN PARA**  

**RETORNAR** "No fue posible reconstruir el mensaje"  

---

## FUNCION Desencriptar(cadena, n, K)
resultado ← ""  
**PARA** cada byte b **EN** cadena **HACER**  
&nbsp;&nbsp;b1 ← b XOR K  
&nbsp;&nbsp;b2 ← RotarDerecha(b1, n)   // inversa de rotación izquierda  
&nbsp;&nbsp;resultado ← resultado + b2  
**FIN PARA**  
**RETORNAR** resultado  
**FIN FUNCION**

---

## FUNCION RotarDerecha(byte, n)
**RETORNAR** ((byte >> n) OR (byte << (8 - n))) AND 0xFF  
**FIN FUNCION**

---

## FUNCION DescomprimirRLE(cadena)
resultado ← ""  
i ← 0  
**MIENTRAS** i < longitud(cadena) **HACER**  
&nbsp;&nbsp;longitud_run ← LeerNumeroDesde(cadena, i)  
&nbsp;&nbsp;simbolo ← cadena[i]  
&nbsp;&nbsp;resultado ← resultado + Repetir(simbolo, longitud_run)  
&nbsp;&nbsp;i ← i + 1  
**FIN MIENTRAS**  
**RETORNAR** resultado  
**FIN FUNCION**

---

## FUNCION DescomprimirLZ78(lista_pares)
diccionario ← []  
resultado ← ""  
**PARA** cada (indice, caracter) **EN** lista_pares **HACER**  
&nbsp;&nbsp;**SI** indice = 0 **ENTONCES**  
&nbsp;&nbsp;&nbsp;&nbsp;entrada ← caracter  
&nbsp;&nbsp;**SINO**  
&nbsp;&nbsp;&nbsp;&nbsp;entrada ← diccionario[indice] + caracter  
&nbsp;&nbsp;**FIN SI**  
&nbsp;&nbsp;resultado ← resultado + entrada  
&nbsp;&nbsp;Añadir entrada a diccionario  
**FIN PARA**  
**RETORNAR** resultado  
**FIN FUNCION**

---

