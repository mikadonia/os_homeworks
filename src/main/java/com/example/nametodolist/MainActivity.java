package com.example.nametodolist;


import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;


import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;


import java.util.ArrayList;

public class MainActivity<manager, TAG> extends AppCompatActivity {
    ArrayAdapter <String> mAdapter;
    ListView listView;
    ArrayList<String> taskList;

    @Override
    protected void onCreate ( Bundle savedInstanceState ) {

        super.onCreate ( savedInstanceState );
        setContentView (R.layout.activity_main );
        final ListView mTaskListView = ( ListView ) findViewById (R.id.list_todo );
        final ArrayList<String> taskList = new ArrayList<>();

        final ArrayAdapter<String> mAdapter = new ArrayAdapter < String > ( this ,
                R.layout.todo_item ,
                R.id.task_title ,
                taskList ) ;
        mTaskListView.setAdapter ( mAdapter );

        final EditText taskEditText = new EditText(this);
        AlertDialog dialog = new AlertDialog.Builder(this)
                . setTitle (" Add a new task " )
                . setMessage ( " What do you want to do next ?")
                . setView ( taskEditText )
                . setPositiveButton (" Add " , new DialogInterface.OnClickListener ()
                {
                    @Override
                    public void onClick ( DialogInterface dialog , int which )
                    {
                        String task = String . valueOf ( taskEditText . getText ()
                        );
                        Log .d(TAG , " Task to add : " + task ) ;
                        taskEditText.setText("");
                    }
                })
                . setNegativeButton (" Cancel " , null )
                . create () ;
        dialog.show();

    }

    @Override
    public boolean onCreateOptionsMenu ( Menu menu ) {
        getMenuInflater(). inflate (R.menu.main_menu, menu );
        return super.onCreateOptionsMenu ( menu ) ;
    }


    private void addItem (String itemText){
        taskList . add ( itemText );
        mAdapter . notifyDataSetChanged () ;
    }
    private void removeItem ( String itemText ) {
        taskList . remove ( itemText );
        mAdapter . notifyDataSetChanged () ;
    }



    final static String TAG = "mmmm";

    @Override
    public boolean onOptionsItemSelected ( MenuItem item ) {
        switch (item.getItemId()) {
            case R.id.action_add_task:
                Log.d(" MainClass ", " Add a new task ");
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }



    }


