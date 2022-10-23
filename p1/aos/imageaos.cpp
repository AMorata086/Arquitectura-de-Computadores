//------------------------------------------------------------------------
// Obtencion de los datos de la imagen SOAAAAAAAAAAAAAAAAAAAAAA
/*Se guardan en una matriz de height filas y width*3 columnas
 *Queda de la forma:
 *Azul11 Verde11 Rojo11 Azul12 Verde12 Rojo12 ...
 *Azul21
 *Azul31
 *.
 */
struct aos_img
{
    int azul;
    int verde;
    int rojo;
};

aos_img image[height * width];

void getDataAOS(struct aos_img image[])
{
    char pixel[3];
    int extra = 4 - ((width * 3) % 4); // Para los bytes de padding
    for (int i = 0; i < height * width; i++)
    {
        inFile.read(pixel, 3);
        image[i].azul = ((int)(unsigned char)pixel[0]);
        image[i].verde = ((int)(unsigned char)pixel[1]);
        image[i].rojo = ((int)(unsigned char)pixel[2]);
        // Si hay padding, lo lee pero no lo guarda
        if (i % (width - 1) == 0 && extra < 4)
            inFile.read(pixel, extra);
    }
}

// Escribir los datos nuevos para SOA
void writeData(int outFile, int height, int width, struct aos_img image[])
{
    char pixel[3];
    char ext[3] = {0, 0, 0};
    int extra = 4 - ((width * 3) % 4); // Para el padding
    for (int i = 0; i < (height * width); i++)
    {
        {
            pixel[0] = image[i].azul;
            pixel[1] = image[i].verde;
            pixel[2] = image[i].rojo;
            outFile.write(pixel, 3);
            // Si hay padding lo escribe al final de la linea
            if (i % (width - 1) == 0 && extra < 4)
                outFile.write(ext, extra);
        }
    }
}