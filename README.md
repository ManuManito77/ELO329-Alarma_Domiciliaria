# ELO329-Alarma_Domiciliaria
## Orden del repositrio

Cada etapa de esta tarea se encuentra en su respectiva rama (branch) del repositorio, el cual se encuentra público para evitar cualquier inconveniente al momento de la revisión. Cada Stage se puede descargar diréctamente como un archivo `.zip` o puede ser clonado localmente.

## Como compilar

*  Etapa 1 y 2:

    Disponibles en las ramas (branch) de *Tarea3__Stage1* y *Tarea3_Stage2*, cada proyecto se debe compilar por separado pero se requieren los mismos comandos de ejecución por consola

    ` g++ *.cpp -o tarea ` -> para compilar todos los archivos y generar el ejecutable llamado *tarea*.

    ` ./tarea config.txt  ` -> para ejecutar el archivo tarea y agregaar como parámetro el nombre del archivo con el que se va a trabajar.

* Etapa 3 y 4:

    Estas etapas se deben ejecutar en *QtCrator* descargando los proyectos de las ramas *Tarea3_Stage3* y *Tarea3_Stage4*. Cada carpeta tendrá un archivo de proyecto de extensión *.pro* que debe ejecutarse para iniciar el proyecto en Qt. Antes de ejecutar el programa se requiere que se ingrese el argumento de la ejecución en `Projects > Run > Command line arguments` agregando `..\container_folder\config.txt`, para seleccionar la carpeta en donde está el archivo config.txt.
