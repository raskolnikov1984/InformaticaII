**ALGORITMO** ReconstruirMensaje
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

**FUNCION** Desencriptar(cadena, n, K)
    resultado ← ""
    **PARA** cada byte b **EN** cadena **HACER**
        b1 ← b XOR K
        b2 ← RotarDerecha(b1, n)   // inversa de rotación izquierda
        resultado ← resultado + b2
    **FIN PARA**
    **RETORNAR** resultado
**FIN FUNCION**  

---

**FUNCION** RotarDerecha(byte, n)
    **RETORNAR** ((byte >> n) OR (byte << (8 - n))) AND 0xFF
**FIN FUNCION**

---

**FUNCION** DescomprimirRLE(cadena)
    resultado ← ""
    i ← 0
    **MIENTRAS** i < longitud(cadena) **HACER**
        longitud_run ← LeerNumeroDesde(cadena, i)
        simbolo ← cadena[i]
        resultado ← resultado + Repetir(simbolo, longitud_run)
        i ← i + 1
    **FIN MIENTRAS**
    **RETORNAR** resultado
**FIN FUNCION**

---

**FUNCION** DescomprimirLZ78(lista_pares)
&nbsp;diccionario ← []
&nbsp;&nbsp;resultado ← ""
    **PARA** cada (indice, caracter) **EN** lista_pares **HACER**
        SI indice = 0 ENTONCES
            entrada ← caracter
        **SINO**
            entrada ← diccionario[indice] + caracter
        **FIN SI**
        resultado ← resultado + entrada
        Añadir entrada a diccionario
    **FIN PARA**
    **RETORNAR** resultado
**FIN FUNCION**
