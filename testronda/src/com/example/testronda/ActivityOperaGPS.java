package com.example.testronda;

import android.location.LocationManager;
import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.view.Menu;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class ActivityOperaGPS extends Activity {

	TextView statusText;
	TextView edLatitude;
	TextView edLongitude;
	private EditText edPontos;  
	private Button btLocalizar;
	private Button btPontoRonda;
	
	static ListaPontos rotaFeita; 
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_activity_opera_gps);
		
		  edLatitude = (TextView) findViewById(R.id.edLatitude);
		  edLongitude = (TextView) findViewById(R.id.edLongitude);
		  statusText = (TextView) findViewById(R.id.ponto_ronda);
		  btPontoRonda = (Button) findViewById(R.id.btponto_ronda);
		  
		Intent intent = getIntent();
		LocationManager locManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);
		// ListaPontos rotaFeita = intent.getParcelableExtra(ExecutaRonda.EXTRA_ROTAFEITA);
		// ListaPontos rotaFeita = new ListaPontos();
				
		new AsyncOperaGPS().execute(statusText, edLatitude, edLongitude, locManager, rotaFeita);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_opera_g, menu);
		return true;
	}

}
