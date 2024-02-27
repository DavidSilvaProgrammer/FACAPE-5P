def bresenham(x1, y1, x2, y2):
    dx = abs(x2 - x1)
    dy = abs(y2 - y1)
    slope = dy / dx

    if slope > 1:
        dx, dy = dy, dx
        x1, y1 = y1, x1
        x2, y2 = y2, x2

    p = 2 * dy - dx
    x, y = x1, y1

    points = [(x, y)]

    for i in range(dx):
        if p < 0:
            p += 2 * dy
        else:
            p += 2 * (dy - dx)
            y += 1 if y2 > y1 else -1
        x += 1 if x2 > x1 else -1

        points.append((x, y))

    return points


/*
Explicação passo a passo de como a função funciona:

    Calcule as diferenças absolutas nas coordenadas x e y:
        dx = abs(x2 - x1)
        dy = abs(y2 - y1)

    Determine a inclinação da linha:
        inclinação = dy / dx

    Se a inclinação for maior que 1 (ou seja, a linha é íngreme), troque os papéis de x e y:
        Troque dx e dy
        Troque x1 e y1
        Troque x2 e y2

    Inicialize o parâmetro de decisão p como:
        p = 2 * dy - dx

    Para cada incremento em x (de 0 a dx - 1):
        Se p for menor que 0, atualize p como:
            p += 2 * dy
        Caso contrário, atualize p como:
            p += 2 * (dy - dx)
            Incremente ou decremente y dependendo se y2 é maior ou menor que y1
        Sempre incremente ou decremente x dependendo se x2 é maior ou menor que x1
        Adicione o ponto (x, y) à lista de pontos

    Retorne a lista de pontos gerados.
*/

