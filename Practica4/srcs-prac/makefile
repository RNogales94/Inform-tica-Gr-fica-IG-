## *********************************************************************
##
## prácticas IG GIM (15-16) - makefile para las prácticas
## (Septiembre de 2015)
##
##  requiere:
##    glut (paquete freeglut)
##    opengl
##    package libjpeg-dev
##    opcionalmente: glew
##
## *********************************************************************

## ---------------------------------------------------------------------
## unidades a enlazar y nombre del binario ejecutable

target_name	:= prac
units_loc   := main practica1 practica2 practica3 practica4 NodoGrafoEscena EntradaNGE rotacion Objeto3D MallaInd MallaRevol MallaPLY material misMateriales textura luz
### nota: añadir a 'units_loc' los módulos practica2 practica3, etc.....

units       := jpg_memsrc jpg_readwrite\
               shaders matrices-tr\
               file_ply_stl\
               aux\
		jpg_imagen
               
## ---------------------------------------------------------------------
## aspectos configurables

opt_dbg_flag  := -g
exit_first    := -Wfatal-errors
warn_all      := -Wall
extra_inc_dir := /opt/local/include

srcs_dir      := ../srcs
include_dir   := ../include
objs_dir      := ../objs

## ---------------------------------------------------------------------
## invocar las definiciones y targets en el archivo 'include.make'

include include.make



