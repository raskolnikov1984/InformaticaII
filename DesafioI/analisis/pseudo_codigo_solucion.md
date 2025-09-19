**ALGORITMO** ReconstruirMensaje
**ENTRADA** mensaje_encriptado, fragmento_original
**SALIDA** mensaje_original, metodo_descompresion, n, K

**PASO 1:** Buscar parametros de descriptacion correctos

**PARA** n **DESDE** 1 **HASTA** 7 **HACER**
    **PARA** K **DESDE** 0 **HASTA** 255 **HACER**
        mensaje_posible = Desencriptar(mensaje_encriptado, n, K)
        **PASO 2:** Probar descompresion con RLE
        mensaje_rle = DescomprimirRLE(mensaje_posible)
        **SI** fragmento_original **ES SUBCADENA DE** mensaje_rle **ENTONCES**
            metodo_compresion = "RLE"
            mensaje_original = mensaje_rle
            RETORNAR (mensaje_original, metodo_comprension, n, K)
        **FIN SI**
        **PASO 3:** Probar descompresión con LZ78
        mensaje_lz ← DescomprimirLZ78(mensaje_posible)
        **SI** fragmento_original **ES SUBCADENA DE** mensaje_lz **ENTONCES**
            metodo_compresion ← "LZ78"
            mensaje_original ← mensaje_lz
            RETORNAR (mensaje_original, metodo_compresion, n, K)
        **FIN SI**
  **FIN PARA**
**FIN PARA**

**RETORNAR**

