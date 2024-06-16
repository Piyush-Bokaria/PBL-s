import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Map;

public class CityPathFinderGUI extends JFrame {
    private final CityGraph cityGraph;
    private final JComboBox<String> startCityComboBox;
    private final JComboBox<String> endCityComboBox;
    private final JTextArea resultTextArea;
    private final JTextField city1TextField;
    private final JTextField city2TextField;
    private final JTextField distanceTextField;

    public CityPathFinderGUI() {
        cityGraph = new CityGraph();
        setTitle("City Path Finder");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(4, 2));

        inputPanel.add(new JLabel("Start City:"));
        startCityComboBox = new JComboBox<>();
        inputPanel.add(startCityComboBox);

        inputPanel.add(new JLabel("End City:"));
        endCityComboBox = new JComboBox<>();
        inputPanel.add(endCityComboBox);

        JButton findPathButton = new JButton("Find Path");
        findPathButton.addActionListener(new FindPathButtonListener());
        inputPanel.add(findPathButton);

        resultTextArea = new JTextArea();
        resultTextArea.setEditable(false);

        JPanel addCityPanel = new JPanel();
        addCityPanel.setLayout(new GridLayout(4, 2));

        addCityPanel.add(new JLabel("City 1:"));
        city1TextField = new JTextField();
        addCityPanel.add(city1TextField);

        addCityPanel.add(new JLabel("City 2:"));
        city2TextField = new JTextField();
        addCityPanel.add(city2TextField);

        addCityPanel.add(new JLabel("Distance:"));
        distanceTextField = new JTextField();
        addCityPanel.add(distanceTextField);

        JButton addPathButton = new JButton("Add Path");
        addPathButton.addActionListener(new AddPathButtonListener());
        addCityPanel.add(addPathButton);

        add(inputPanel, BorderLayout.NORTH);
        add(new JScrollPane(resultTextArea), BorderLayout.CENTER);
        add(addCityPanel, BorderLayout.SOUTH);
    }

    private boolean comboBoxContainsItem(JComboBox<String> comboBox, String item) {
        for (int i = 0; i < comboBox.getItemCount(); i++) {
            if (comboBox.getItemAt(i).equals(item)) {
                return true;
            }
        }
        return false;
    }

    private class AddPathButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String city1 = city1TextField.getText().trim();
            String city2 = city2TextField.getText().trim();
            String distanceStr = distanceTextField.getText().trim();

            if (city1.isEmpty() || city2.isEmpty() || distanceStr.isEmpty()) {
                resultTextArea.setText("Please enter both cities and the distance.");
                return;
            }

            int distance;
            try {
                distance = Integer.parseInt(distanceStr);
            } catch (NumberFormatException ex) {
                resultTextArea.setText("Please enter a valid distance.");
                return;
            }

            cityGraph.addCity(city1);
            cityGraph.addCity(city2);
            cityGraph.addPath(city1, city2, distance);

            if (!comboBoxContainsItem(startCityComboBox, city1)) {
                startCityComboBox.addItem(city1);
            }
            if (!comboBoxContainsItem(startCityComboBox, city2)) {
                startCityComboBox.addItem(city2);
            }
            if (!comboBoxContainsItem(endCityComboBox, city1)) {
                endCityComboBox.addItem(city1);
            }
            if (!comboBoxContainsItem(endCityComboBox, city2)) {
                endCityComboBox.addItem(city2);
            }

            city1TextField.setText("");
            city2TextField.setText("");
            distanceTextField.setText("");

            resultTextArea.setText("Path added successfully.");
        }
    }

    private class FindPathButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            String startCity = (String) startCityComboBox.getSelectedItem();
            String endCity = (String) endCityComboBox.getSelectedItem();

            if (startCity == null || endCity == null) {
                resultTextArea.setText("Please select both start and end cities.");
                return;
            }

            if (startCity.equals(endCity)) {
                resultTextArea.setText("Start city and end city are the same.");
                return;
            }

            Map<String, Integer> distances = cityGraph.dijkstra(startCity);
            Integer distance = distances.get(endCity);

            if (distance == Integer.MAX_VALUE) {
                resultTextArea.setText("No path found between " + startCity + " and " + endCity + ".");
            } else {
                resultTextArea.setText("Shortest path from " + startCity + " to " + endCity + " is " + distance + " units.");
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CityPathFinderGUI gui = new CityPathFinderGUI();
            gui.setVisible(true);
        });
    }
}
