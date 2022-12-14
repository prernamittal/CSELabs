import javafx.application.*;
import javafx.beans.value.ChangeListener;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.event.*;
import javafx.beans.value.*;

public class javafxbasic extends Application {
    //for displaying checked items
    Label selected,check;
    CheckBox c1,c2;
    public static void main(String[] args) {
        launch(args);
    }
    @Override
    public void start(Stage mystage) {
        mystage.setTitle("Hello World!");
        GridPane grid = new GridPane();
        Scene myscene = new Scene(grid,500,500);
        mystage.setScene(myscene);

        //label(text)
        Label mylabel = new Label("This is a label\n");
        grid.addRow(0,mylabel);

        //normal button
        Button btn = new Button("Button"); 
        grid.addRow(1,btn);

        //radio button
        Label select = new Label("Select an option");
        ToggleGroup group = new ToggleGroup();
        RadioButton rbtn1 = new RadioButton("apple");
        RadioButton rbtn2 = new RadioButton("orange");
        rbtn1.setToggleGroup(group);
        rbtn2.setToggleGroup(group);
        rbtn1.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae){
                select.setText("apple is selected");                
            }
        });
        rbtn2.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent ae){
                select.setText("orange is selected");                
            }
        });
        grid.addRow(2,rbtn1,rbtn2,select);

        //checkbox
        check=new Label("select items");
        selected= new Label("");
        c1=new CheckBox("laptop");
        c2=new CheckBox("mouse");
        c1.setOnAction(new EventHandler<ActionEvent>(){
            public void handle(ActionEvent ae){
                if(c1.isSelected()){
                    check.setText("laptop is checked");
                }
                else{
                    check.setText("laptop is unchecked");
                }
                showAll();
            }
        });
        c2.setOnAction(new EventHandler<ActionEvent>(){
            public void handle(ActionEvent ae){
                if(c2.isSelected()){
                    check.setText("mouse is checked");
                }
                else{
                    check.setText("mouse is unchecked");
                }
                showAll();
            }
        });
        showAll();
        grid.addRow(3,c1,c2,check);
        grid.addRow(4, selected);

        //textfield
        Label user= new Label("Username: ");
        Label pwd= new Label("Password");
        TextField t1=new TextField();
        PasswordField t2=new PasswordField();
        grid.addRow(5, user, t1);
        grid.addRow(6,pwd,t2);

        //button press event
        Label response=new Label("press submit");
        Button submit = new Button("Submit");
        submit.setOnAction((ae) -> response.setText("submitted"));
        // submit.setOnAction(new EventHandler<ActionEvent>(){
        //     public void handle(ActionEvent ae){
        //         response.setText("Submitted");
        //     }
        // });
        grid.addRow(7,submit,response);

        //combo box
        ObservableList<Integer>numbers= FXCollections.observableArrayList(1,2,3,4);
        ComboBox<Integer> num= new ComboBox<Integer>(numbers);
        Label msg = new Label();
        msg.setText("selected num is "+num.getValue());
        num.setOnAction((ae)-> msg.setText("selected num is "+num.getValue()));
        grid.addRow(8,num,msg);

        //toggle button
        Label status = new Label("Push the switch");
        ToggleButton onoff = new ToggleButton("On/Off");
        onoff.setOnAction(new EventHandler<ActionEvent>(){
            public void handle(ActionEvent ae){
                if(onoff.isSelected())
                    status.setText("switch is on");
                else
                    status.setText("switch is off");    
            }
        });
        grid.addRow(9,onoff,status);

        //ListView (single selection)
        Label prompt=new Label("Select something: ");
        ObservableList<String>langlist=FXCollections.observableArrayList("Java","Python","c","c++","c#");
        ListView<String>lang=new ListView<String>(langlist);
        lang.setPrefSize(100,70);
        MultipleSelectionModel<String>mul=lang.getSelectionModel();
        mul.selectedItemProperty().addListener(new ChangeListener<String>() {
            public void changed(ObservableValue<? extends String>changed, String oldval, String newval){
                prompt.setText("selected: "+newval);
            }            
        });
        grid.addRow(10,lang,prompt);

        //display stage and scene
        mystage.show();
    }
//method for displaying all checked items
    void showAll(){
        String items="";
        if(c1.isSelected())
        items=" laptop";
        if(c2.isSelected())
        items+=" mouse";
        selected.setText("Items checked are: "+items);
    }
}