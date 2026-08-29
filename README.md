# Proyecto Arduino

> Fundamentos de Electrónica – 1º semestre •
> Universidad Autónoma de Occidente, Culiacán

## Repartición de versiones

- Integrante 1 — V1
- Integrante 2 — V2
- Integrante 3 — V3
- Integrante 4 — V4 (Versión final, entregable)

## Requisitos previos

Para desarrollar comodamente y contribuir sin conflictos en la arquitectura del proyecto, deberás contar con estos requisitos:

- [Visual Studio Code](https://code.visualstudio.com/Download)
- [Extensión de Visual Studio Code: Wokwi Simulator](https://marketplace.visualstudio.com/items?itemName=Wokwi.wokwi-vscode)
- [Extensión de Visual Studio Code: PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
- [Cuenta en Wokwi.com](https://wokwi.com/)
- [Cuenta de GitHub](https://github.com/)
- Instalar Git:
  - [`Windows`](https://git-scm.com/install/windows)
  - [`Linux`](https://git-scm.com/install/linux)
  - [`macOS`](https://git-scm.com/install/mac)

## Flujo de trabajo (IMPORTANTE)

> [!IMPORTANT]
> Cada versión debe partir de la versión anterior terminada.

### Clonar el repositorio

La primera vez que trabajes en el proyecto:

```
git clone https://github.com/ewwhenry/ITDS295-proyecto-arduino.git
cd ITDS295-proyecto-arduino
```

### Preparar la rama de la versión

Antes de comenzar una versión, asegúrate de estar en `main` y tener la versión anterior actualizada:

```
git switch main
git pull
```

Después, crea la rama correspondiente a la versión que vas a desarrollar.

Por ejemplo, para V1:

```
git switch -c feature/v1
```

Para V2:

```
git switch -c feature/v2
```

Para V3:

```
git switch -c feature/v3
```

Para V4:

```
git switch -c feature/v4
```

> [!WARNING]
> No crees la rama de una versión nueva hasta que la versión anterior haya sido integrada a `main`.

### Desarrollo

- El integrante responsable desarrolla su versión.
- Verifica que el proyecto compile y funcione correctamente.
- Realiza un commit de los cambios.
- Sube su rama a GitHub.
- Avisa en el grupo que terminó y subió sus cambios.
- El líder del proyecto revisa los cambios y los integra a `main`.
- Una vez integrada la versión, el siguiente integrante puede comenzar su versión desde el `main` actualizado.

---

### Cómo subir cambios al repositorio de GitHub

#### Agregar los cambios

```
git add .
```

#### Crear el commit

Reemplaza X con el número de la versión:

```
git commit -m "feat(vX): <Descripción de los cambios>"
```

Ejemplo:

```
git commit -m "feat(v1): implementa circuito base"
```

#### Subir la rama

Reemplaza X con el número de la versión:

```
git push -u origin feature/vX
```

Ejemplo:

```
git push -u origin feature/v1
```

> [!WARNING]
> No realices cambios directamente sobre `main`. Siempre trabaja en la rama feature/vX correspondiente a tu versión.

#### Al terminar

Avisa en el grupo que terminaste tu versión y subiste tus cambios para que el líder del proyecto pueda revisarlos e integrarlos a `main`.

> [!IMPORTANT]
> Una versión se considera terminada cuando:
>
> - Todas sus tareas están completadas.
> - El proyecto compila correctamente.
> - El circuito funciona correctamente.
> - Los cambios han sido integrados a `main`.
>
> Una vez cumplidos estos requisitos, el siguiente integrante puede comenzar su versión.

## Versiones

Caracteristicas de cada versión:

### V1 — Bases

- Crear el primer diagrama (`diagram.json`)
- Agregar componentes básicos:
  - Arduino UNO
  - Protoboard (también llamada Breadboard)
  - Led
  - Buzzer

#### Tareas

- Hacer que el led encienda durante **`200 milisegundos`** cada **`2 segundos`**.
- Hacer que el buzzer suene durante **`200 milisegundos`** cada **`2 segundos`**.

_Ambas cosas al mismo tiempo._

#### Objetivo:

Sentar las bases del diagrama (`diagram.json`) y crear un punto de partida en el codigo (`src/main.cpp`).

### V2 — Modularización + 1 característica

> _Apartir de la V1..._

- Crear funciones
- Limpiar y actualizar código anterior

#### Tareas

- **Crear función para emitir sonido en el buzzer**, a fin de hacer de esta una función reutilizable. Ésta función deberá permitir indicar durante cuanto tiempo (en milisegundos `ms`) sonará el buzzer.
- **Crear función para encender el led**. Deberá permitir indicar en que pin enviar la señal a fin de poder reutilizar esta función para cualquier otro led.
- **Crear función para apagar el led**. De igual manera, permitir indicar a que pin enviar la señal de apagado.
- **Actualizar el código anterior para usar las nuevas funciones**. Ésto para mantener un código ordenado y un desarrollo más limpio.

### V3 — Integrante 3

Parte de V2 y agrega:

> Por definir

### V4 — Integrante 4

Versión final:

> Por definir

- [ ] Documentación
- [ ] Pruebas finales
