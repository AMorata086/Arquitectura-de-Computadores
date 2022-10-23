#include <fstream>

//------------------------------------------------------------------------
// Obtencion de los datos de la imagen SOAAAAAAAAAAAAAAAAAAAAAA
/*Se guardan en una matriz de height filas y width*3 columnas
 *Queda de la forma:
 *Azul11 Verde11 Rojo11 Azul12 Verde12 Rojo12 ...
 *Azul21
 *Azul31
 *.
 */

struct soa_img
{
    int rojo[height * width];
    int verde[height * width];
    int azul[height * width];
}

void
getDataSOA(struct soa_img image)
{
    char pixel[3];
    int extra = 4 - ((width * 3) % 4); // Para los bytes de padding
    for (int i = 0; i < (height * width); i++)
    {
        inFile.read(pixel, 3);

        image.azul[i] = ((int)(unsigned char)pixel[0]);
        image.verde[i] = ((int)(unsigned char)pixel[1]);
        image.rojo[i] = ((int)(unsigned char)pixel[2]);
        // Si hay padding, lo lee pero no lo guarda
        if (i % (width - 1) == 0 && extra < 4)
            inFile.read(pixel, extra);
    }
}

// Escribir los datos nuevos para SOA
void writeDataSOA(struct soa_img image)
{
    char pixel[3]; // es 4?
    char ext[3] = {0, 0, 0};
    int extra = 4 - ((width * 3) % 4); // Para el padding
    for (int i = 0; i < (height * width); i++)
    {
        {
            pixel[0] = image.azul[i];
            pixel[1] = image.verde[i];
            pixel[2] = image.rojo[i];
            outFile.write(pixel, 3);
            // Si hay padding lo escribe al final de la linea
            if (i % (width - 1) == 0 && extra < 4)
                outFile.write(ext, extra);
        }
    }
}