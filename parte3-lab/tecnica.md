# Parte 3.B - Técnica de Hacking Ejecutada e Interpretación

## 1. Comando Ejecutado
Se realizó un escaneo agresivo y completo de puertos y servicios contra la máquina pública del laboratorio utilizando la herramienta Nmap:

```bash
nmap -p- -sV -sC 172.16.10.10
```

## 2. Explicación de la Técnica (Qué hace y por qué funciona)
La técnica utilizada es un **Escaneo Activo de Puertos y Detección de Servicios**. 
* **Qué hace:** Revisa los 65,535 puertos de comunicación de la máquina víctima (`-p-`), identifica los programas que están escuchando (`-sV`) y lanza scripts de prueba automáticos (`-sC`) para extraer datos del sistema.
* **Por qué funciona:** Funciona porque el contenedor del laboratorio `p-web-01` está configurado intencionalmente para simular un servidor web productivo expuesto, manteniendo un puerto abierto para recibir conexiones de los usuarios de la red pública.

## 3. Información Obtenida e Interpretación Técnica

El escaneo de Nmap arrojó el siguiente resultado crítico:
* **Puerto Abierto:** `8081/tcp` se encuentra en estado `open`.
* **Servicio Detectado:** Un servidor web `http`.
* **Software y Versión:** `Werkzeug httpd 3.0.1` corriendo sobre `Python 3.12.3`.
* **Título de la Web:** El script automático detectó que la página web tiene como título la palabra `"Menu"`.

### Análisis Crítico:
El descubrimiento del servidor web **Werkzeug** revela que la aplicación está desarrollada utilizando un entorno de desarrollo basado en Python (como Flask o Django). En un entorno real de producción, el uso de Werkzeug expuesto directamente en el puerto 8081 se considera una mala práctica de seguridad. Si el modo de depuración (*debug mode*) se encuentra encendido, un atacante podría aprovechar la consola interactiva para ejecutar código de forma remota y tomar control total del contenedor público, usándolo como puente para saltar hacia la red corporativa interna (`10.1.0.0/24`).

## 4. Evidencia Visual del Ataque
![Resultado del Escaneo Nmap](nmap_scan.PNG)
