#if 0
from collections import deque, defaultdict

def create_graph(data) :
    graph = {}

    for edge in data :
node_a, node_b, distance = edge

if node_a not in graph :
graph[node_a] = {}
graph[node_a][node_b] = distance

if node_b not in graph :
graph[node_b] = {}
graph[node_b][node_a] = distance

return graph

def bfs(graph) :
    q = deque()
    visited_dist = defaultdict(int)
    start_node = 1
    dist = 0

    visited_dist[start_node] = dist
    q.append(start_node)

    while q:
node = q.popleft()
neighbors = graph[node]
print(visited_dist)
for neighbor in neighbors :
if neighbor not in visited_dist :
dist += neighbors[neighbor]
visited_dist[neighbor] = dist
q.append(neighbor)

return 0


def solution(N, road, K) :
    answer = 0
    graph = create_graph(road)
    bfs(graph)
    return answer
#endif