import java.util.*;

public class CityGraph {
    private final Map<String, List<Edge>> adjacencyList;

    public CityGraph() {
        this.adjacencyList = new HashMap<>();
    }

    public void addCity(String city) {
        adjacencyList.putIfAbsent(city, new ArrayList<>());
    }

    public void addPath(String fromCity, String toCity, int distance) {
        adjacencyList.get(fromCity).add(new Edge(toCity, distance));
        adjacencyList.get(toCity).add(new Edge(fromCity, distance)); 
    }

    public List<String> getCities() {
        return new ArrayList<>(adjacencyList.keySet());
    }

    public Map<String, Integer> dijkstra(String startCity) {
        PriorityQueue<Edge> priorityQueue = new PriorityQueue<>(Comparator.comparingInt(e -> e.distance));
        Map<String, Integer> distances = new HashMap<>();
        Set<String> visited = new HashSet<>();

        for (String city : adjacencyList.keySet()) {
            distances.put(city, Integer.MAX_VALUE);
        }
        distances.put(startCity, 0);
        priorityQueue.add(new Edge(startCity, 0));

        while (!priorityQueue.isEmpty()) {
            Edge current = priorityQueue.poll();
            if (!visited.add(current.city)) continue;

            for (Edge edge : adjacencyList.get(current.city)) {
                if (visited.contains(edge.city)) continue;

                int newDist = distances.get(current.city) + edge.distance;
                if (newDist < distances.get(edge.city)) {
                    distances.put(edge.city, newDist);
                    priorityQueue.add(new Edge(edge.city, newDist));
                }
            }
        }
        return distances;
    }

    private static class Edge {
        String city;
        int distance;

        Edge(String city, int distance) {
            this.city = city;
            this.distance = distance;
        }
    }
}
