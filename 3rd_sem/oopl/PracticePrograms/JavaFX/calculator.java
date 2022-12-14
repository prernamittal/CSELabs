import javafx.application.*;
// import javafx.beans.value.ChangeListener;
// import javafx.beans.value.*;
// import javafx.collections.FXCollections;
// import javafx.collections.ObservableList;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.event.*;

public class calculatorfx extends Application {
    //for displaying checked items
    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage mystage) {
        mystage.setTitle("calculator");
        GridPane grid = new GridPane();
        Scene myscene = new Scene(grid,500,500);
        mystage.setScene(myscene);
        //text field
        Label first = new Label("Enter first number: ");
        Label second = new Label("Enter second number: ");
        TextField f= new TextField();
        TextField s=new TextField();
        Label prompt=new Label("Select operation: ");
        Label result= new Label("result is: ");

        // //combo box
        // ObservableList<String>operation=FXCollections.observableArrayList("add","subtract");
        // ComboBox<String>op= new ComboBox<String>(operation);

        //radiobutton
        ToggleGroup operation = new ToggleGroup();
        RadioButton add = new RadioButton("add");
        RadioButton sub = new RadioButton("subtract");
        RadioButton mul = new RadioButton("multiply");
        RadioButton div = new RadioButton("divide");
        add.setToggleGroup(operation);
        sub.setToggleGroup(operation);
        mul.setToggleGroup(operation);
        div.setToggleGroup(operation);
        add.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae){
                Double a = getDoubleFromTextField(f);
                double b = getDoubleFromTextField(s);
                result.setText(String.valueOf(a + b));
        }
        });
        sub.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae){
                Double a = getDoubleFromTextField(f);
                double b = getDoubleFromTextField(s);
                result.setText(String.valueOf(a - b));
        }
        });
        mul.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae){
                Double a = getDoubleFromTextField(f);
                double b = getDoubleFromTextField(s);
                result.setText(String.valueOf(a * b));
        }
        });
        div.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae){
                Double a = getDoubleFromTextField(f);
                double b = getDoubleFromTextField(s);
                result.setText(String.valueOf(a / b));
        }
        });

        //calculate button
        // Button cal =  new Button("Calculate");
        // cal.setOnAction(new EventHandler<ActionEvent>() {
        //     public void handle(ActionEvent ae){
                    // Double a = getDoubleFromTextField(f);
                    // double b = getDoubleFromTextField(s);
                    // result.setText(String.valueOf(a - b));
        //     }
        // });
        //display grid
        grid.addRow(0,first,f);
        grid.addRow(1,second,s);
        grid.addRow(2,prompt);
        grid.addRow(3, add,sub,mul,div);
        grid.addRow(4,result);

        // grid.addRow(2,prompt,op);
        // grid.addRow(3,cal);
        //display stage
        mystage.show();
    }
    double getDoubleFromTextField(TextField t) {
        return Double.parseDouble(t.getText());
    }
}
