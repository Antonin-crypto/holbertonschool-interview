#!/usr/bin/python3
import sys
import signal

# Initialisation des variables
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
line_count = 0
total_size = 0
status_count = {code: 0 for code in status_codes}

# Fonction pour traiter une ligne
def process_line(line):
    global total_size
    global line_count
    parts = line.split(' ')

    # Vérification si la ligne est bien formatée
    if len(parts) != 9:
        return

    try:
        # Extraction des informations pertinentes
        status_code = parts[8]
        file_size = int(parts[7])

        # Mise à jour du compteur total de taille et des statuts
        total_size += file_size
        if status_code in status_count:
            status_count[status_code] += 1

    except ValueError:
        # Si la ligne n'est pas dans le bon format (valeurs incorrectes)
        return

    line_count += 1

    # Si 10 lignes sont traitées, on affiche les statistiques
    if line_count % 10 == 0:
        print_metrics()

# Fonction pour afficher les métriques
def print_metrics():
    print(f"Total file size: {total_size}")
    for code in sorted(status_codes):
        if status_count[code] > 0:
            print(f"{code}: {status_count[code]}")

# Fonction pour gérer l'interruption par CTRL + C
def handle_interrupt(signal, frame):
    print_metrics()
    sys.exit(0)

# Enregistrement du gestionnaire d'interruption
signal.signal(signal.SIGINT, handle_interrupt)

# Lecture ligne par ligne depuis stdin
if __name__ == "__main__":
    try:
        for line in sys.stdin:
            process_line(line)
    except EOFError:
        print_metrics()
