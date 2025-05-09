import socket
import threading
import pickle

players = [(100, 100), (300, 100)]  # Starting positions

def handle_client(conn, player_id):
    conn.send(pickle.dumps(player_id))  # Send player ID
    conn.send(pickle.dumps(players[player_id]))  # Send starting position

    while True:
        try:
            data = pickle.loads(conn.recv(1024))
            players[player_id] = data
            conn.sendall(pickle.dumps(players))
        except:
            break
    conn.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(("localhost", 5555))
server.listen(2)
print("[SERVER] Waiting for connections...")

player_id = 0
while player_id < 2:
    conn, addr = server.accept()
    print(f"[SERVER] Player {player_id} connected from {addr}")
    threading.Thread(target=handle_client, args=(conn, player_id)).start()
    player_id += 1