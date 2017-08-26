package com.example.testronda;

import java.util.ArrayList;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.support.v4.app.NavUtils;
import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.content.Intent;
import android.os.Build;

public class EscolhaRonda extends Activity {

	public final static String EXTRA_NOMERONDA = "com.example.testronda.NOMERONDA";
	public static String username;
	public static String password;
	public ListView listaRondas;
	ArrayList<String> nomeRondas = new ArrayList<String>();

	@SuppressLint("NewApi")
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_escolha_ronda);
		
		// Make sure we're running on Honeycomb or higher to use ActionBar APIs
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
            // Show the Up button in the action bar.
            getActionBar().setDisplayHomeAsUpEnabled(true);
            // Show the Up button in the action bar.
    		setupActionBar();
    		
    		// Get login information
    		Intent intent = getIntent();
    		username = intent.getStringExtra(MainActivity.EXTRA_USERNAME);    		
    		password = intent.getStringExtra(MainActivity.EXTRA_PASSWORD);    
    		
    		// Pegar a lista de rondas aqui e montar a lista
    		preencheRondas();
    		listaRondas = (ListView) findViewById(R.id.lista_rondas);
    		ArrayAdapter adapter = new ArrayAdapter<String>(this,android.R.layout.simple_list_item_single_choice, nomeRondas);
    		listaRondas.setAdapter(adapter);
    		listaRondas.setChoiceMode(ListView.CHOICE_MODE_SINGLE);
    		listaRondas.setSelection(1);
        }
		
	}

	private void preencheRondas() {

		// FIXME!!!
		nomeRondas.clear();
		nomeRondas.add("Ronda 1");
		nomeRondas.add("Ronda 2");
        nomeRondas.add("Ronda 3");
        nomeRondas.add("Ronda 4");
        nomeRondas.add("Ronda 5");
	}

	/**
	 * Set up the {@link android.app.ActionBar}, if the API is available.
	 */
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	private void setupActionBar() {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
			getActionBar().setDisplayHomeAsUpEnabled(true);
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.escolha_ronda, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
		case android.R.id.home:
			// This ID represents the Home or Up button. In the case of this
			// activity, the Up button is shown. Use NavUtils to allow users
			// to navigate up one level in the application structure. For
			// more details, see the Navigation pattern on Android Design:
			//
			// http://developer.android.com/design/patterns/navigation.html#up-vs-back
			//
			NavUtils.navigateUpFromSameTask(this);
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	public void rondaEscolhida(View view) {
	    // Do something in response to login
		Intent intent = new Intent(this, ExecutaRonda.class);
		
		// Enviar a ronda escolhida
		// EditText editText = (EditText) findViewById(R.id.login_name);
		// String nomeronda = editText.getText().toString();
		//public void onItemClick(AdapterView<?> myAdapter, View myView, int myItemInt, long mylng) {
	    //    String selectedFromList =(String) (lv.getItemAtPosition(myItemInt));
	        
		int selection = listaRondas.getSelectedItemPosition();
		//String rondaEscolhida = nomeRondas.get(selection);
		// String rondaEscolhida = (String) listaRondas.getItemAtPosition(selection);
		// FIXME!!!
		String rondaEscolhida = "Ronda";
		intent.putExtra(EXTRA_NOMERONDA, rondaEscolhida);
		
	    startActivity(intent);
	}
}
