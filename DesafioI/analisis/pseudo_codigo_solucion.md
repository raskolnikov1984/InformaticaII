**ALGORITMO** ReconstruirMensaje
**ENTRADA:** mensaje_encriptado, fragmento_original  
**SALIDA:** mensaje_original, metodo_compresion, n, K  

---

### PASO 1: Buscar parámetros de desencriptación correctos

**PARA** n **DESDE** 1 **HASTA** 7 **HACER**  
&nbsp;&nbsp;**PARA** K **DESDE** 0 **HASTA** 255 **HACER**  
&nbsp;&nbsp;&nbsp;&nbsp;mensaje_posible ← Desencriptar(mensaje_encriptado, n, K)
&nbsp;&nbsp;&nbsp;&nbsp;### PASO 2: Probar descompresión con RLE  
&nbsp;&nbsp;&nbsp;&nbsp;mensaje_rle ← DescomprimirRLE(mensaje_posible)  
&nbsp;&nbsp;&nbsp;&nbsp;**SI** fragmento_original **ES SUBCADENA DE** mensaje_rle **ENTONCES**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;metodo_compresion ← "RLE"
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mensaje_original ← mensaje_rle  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**RETORNAR** (mensaje_original, metodo_compresion, n, K)  
&nbsp;&nbsp;&nbsp;&nbsp;**FIN SI**  

&nbsp;&nbsp;&nbsp;&nbsp;### PASO 3: Probar descompresión con LZ78  
&nbsp;&nbsp;&nbsp;&nbsp;mensaje_lz ← DescomprimirLZ78(mensaje_posible)  
&nbsp;&nbsp;&nbsp;&nbsp;**SI** fragmento_original **ES SUBCADENA DE** mensaje_lz **ENTONCES**  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;metodo_compresion ← "LZ78"  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;mensaje_original ← mensaje_lz  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;**RETORNAR** (mensaje_original, metodo_compresion, n, K)  
&nbsp;&nbsp;&nbsp;&nbsp;**FIN SI**  

&nbsp;&nbsp;**FIN PARA**  
**FIN PARA**  

**RETORNAR** "No fue posible reconstruir el mensaje"
