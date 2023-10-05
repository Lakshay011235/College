package src;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class TaskManager extends Application {

    private ObservableList<Task> tasks;
    private ListView<Task> taskListView;
    private TextField titleField;
    private TextArea descriptionArea;
    private DatePicker dueDatePicker;
    private ComboBox<String> priorityComboBox;
    private ComboBox<String> categoryComboBox;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        tasks = FXCollections.observableArrayList();

        taskListView = new ListView<>();
        taskListView.setPrefWidth(400);
        taskListView.setItems(tasks);

        Button addButton = new Button("Add Task");
        addButton.setOnAction(event -> addTask());

        Button editButton = new Button("Edit Task");
        editButton.setOnAction(event -> editTask());

        Button deleteButton = new Button("Delete Task");
        deleteButton.setOnAction(event -> deleteTask());

        HBox buttonsBox = new HBox(10, addButton, editButton, deleteButton);
        buttonsBox.setAlignment(Pos.CENTER);

        GridPane inputGrid = new GridPane();
        inputGrid.setHgap(10);
        inputGrid.setVgap(10);
        inputGrid.setPadding(new Insets(10));

        Label titleLabel = new Label("Title:");
        titleField = new TextField();

        Label descriptionLabel = new Label("Description:");
        descriptionArea = new TextArea();

        Label dueDateLabel = new Label("Due Date:");
        dueDatePicker = new DatePicker();

        Label priorityLabel = new Label("Priority:");
        priorityComboBox = new ComboBox<>();
        priorityComboBox.getItems().addAll("Low", "Medium", "High");

        Label categoryLabel = new Label("Category:");
        categoryComboBox = new ComboBox<>();
        categoryComboBox.getItems().addAll("Personal", "Work", "Study");

        inputGrid.addColumn(0, titleLabel, descriptionLabel, dueDateLabel, priorityLabel, categoryLabel);
        inputGrid.addColumn(1, titleField, descriptionArea, dueDatePicker, priorityComboBox, categoryComboBox);

        VBox root = new VBox(10, taskListView, buttonsBox, inputGrid);
        root.setPadding(new Insets(10));

        primaryStage.setScene(new Scene(root, 600, 400));
        primaryStage.setTitle("Task Manager");
        primaryStage.show();
    }

    private void addTask() {
        String title = titleField.getText();
        String description = descriptionArea.getText();
        String dueDate = dueDatePicker.getValue().toString();
        String priority = priorityComboBox.getValue();
        String category = categoryComboBox.getValue();

        Task task = new Task(title, description, dueDate, priority, category);
        tasks.add(task);

        clearFields();
    }

    private void editTask() {
        Task selectedTask = taskListView.getSelectionModel().getSelectedItem();
        if (selectedTask != null) {
            titleField.setText(selectedTask.getTitle());
            descriptionArea.setText(selectedTask.getDescription());
            dueDatePicker.setValue(selectedTask.getDueDate());
            priorityComboBox.setValue(selectedTask.getPriority());
            categoryComboBox.setValue(selectedTask.getCategory());

            tasks.remove(selectedTask);
        }
    }

    private void deleteTask() {
        Task selectedTask = taskListView.getSelectionModel().getSelectedItem();
        if (selectedTask != null) {
            tasks.remove(selectedTask);
        }
    }

    private void clearFields() {
        titleField.clear();
        descriptionArea.clear();
        dueDatePicker.setValue(null);
        priorityComboBox.getSelectionModel().clearSelection();
        categoryComboBox.getSelectionModel().clearSelection();
    }

    public class Task {

        private String title;
        private String description;
        private String dueDate;
        private String priority;
        private String category;

        public Task(String title, String description, String dueDate, String priority, String category) {
            this.title = title;
            this.description = description;
            this.dueDate = dueDate;
            this.priority = priority;
            this.category = category;
        }

        public String getTitle() {
            return title;
        }

        public String getDescription() {
            return description;
        }

        public String getDueDate() {
            return dueDate;
        }

        public String getPriority() {
            return priority;
        }

        public String getCategory() {
            return category;
        }

        @Override
        public String toString() {
            return title;
        }
    }
}

