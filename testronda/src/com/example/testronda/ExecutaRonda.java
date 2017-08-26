package com.example.testronda;

import java.util.ArrayList;
import java.util.List;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.util.EntityUtils;
import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.app.Activity;
import android.app.AlarmManager;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.support.v4.app.NavUtils;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class ExecutaRonda extends Activity {

	public final static String EXTRA_LOCMANAGER = "com.example.testronda.LOCMANAGER";
	public final static String EXTRA_ROTAFEITA = "com.example.testronda.ROTAFEITA";
	
	private final static int CONNECTION_FAILURE_RESOLUTION_REQUEST = 9000;
	
	private List<String> descricaoRota; 
	
	TextView statusText;
	TextView edLatitude;
	TextView edLongitude;
	private EditText edPontos;  
	private Button btLocalizar;
	private Button btPontoRonda;
	private Button btFinalizaRonda;
	private Double longitudePto = -47.041100, latitudePto = -22.879106;	
	Location locat; 
	LocationManager locManager;
	ListaPontos rotaFeita;
	AsyncTask<Object, Void, Ponto> task;
	
	@SuppressLint("NewApi")	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_executa_ronda);

		// Make sure we're running on Honeycomb or higher to use ActionBar APIs
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
            // Show the Up button in the action bar.
            getActionBar().setDisplayHomeAsUpEnabled(true);
            // Show the Up button in the action bar.
    		setupActionBar();
        }
        
		  edLatitude = (TextView) findViewById(R.id.edLatitude);
		  edLongitude = (TextView) findViewById(R.id.edLongitude);
		  statusText = (TextView) findViewById(R.id.ponto_ronda);
		  btPontoRonda = (Button) findViewById(R.id.btproximoponto_ronda);
		  btFinalizaRonda = (Button) findViewById(R.id.btfinaliza_ronda);
		  btFinalizaRonda.setEnabled(false);

		// Pegar informação da ronda
		rotaFeita = new ListaPontos();
		descricaoRota = new ArrayList<String>();
		Intent intent = getIntent();
		String nomeRonda = intent.getStringExtra(EscolhaRonda.EXTRA_NOMERONDA);    
		// new AsyncDescricaoRonda().execute(nomeRonda);
		statusText.setText("Vamos comecar a rota: " + nomeRonda);
		
		// FIXME!!!
		/*
		try {
			  Settings.Secure.setLocationProviderEnabled(getContentResolver(), LocationManager.GPS_PROVIDER, true);
			} catch (Exception e) {
				statusText.setText("Deu problema para ligar provider: " + e.getMessage());
			  Log.e("ExecutaRonda", e.getMessage());
		}
		*/
	}

	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	private void setupActionBar() {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
			getActionBar().setDisplayHomeAsUpEnabled(true);
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.executa_ronda, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
		case android.R.id.home:

			NavUtils.navigateUpFromSameTask(this);
			return true;
		}
		return super.onOptionsItemSelected(item);
	}
	
	public void descarregaRota(View view) {
	    // Fazer as coisas de final de ronda, 1) desabilitar GPS, 2) se tudo enviado, matar asynctask
		// de envio de dados, 3) deletar estruturas de dados, se necessário
		Intent intent = new Intent(this, FinalizaRonda.class);
		
		// Enviar a ronda escolhida
		// EditText editText = (EditText) findViewById(R.id.login_name);
		// String nomeronda = editText.getText().toString();
		// String nomeRonda = "Ronda Teste";
		// intent.putExtra(EXTRA_NOMERONDA, nomeRonda);
		
		// Desabilitar AsyncTask de GPS em background
		task.cancel(true);
		
		// Chamar metodo que deve enviar todos os pontos remanescentes dve ser chamado no GPS background, no OnCancel!!!
		
	    startActivity(intent);
	}

	public void enviaPonto(View view) {
		
	    Double latitude = Double.valueOf(edLatitude.getText().toString());
	    Double longitude = Double.valueOf(edLongitude.getText().toString());
		new AsyncEnviaDadosRonda().execute("http://multidot.com.br/mr/mr.php?usuario=teste&ronda=ronda_teste&lon="+longitude+"&lat="+latitude+"&cp=s", statusText);
	}
	
	public void testGPSlocation(View view) {
		
		locManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);

		//btPontoRonda.setEnabled(false);
		
		// Testar se o provider GPS está OK, e trocar a tag para Finalizar ronda se sim e se iniciar
        Criteria criteria = new Criteria();
        criteria.setAccuracy(Criteria.ACCURACY_FINE);
        LocationManager locManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);
        String provider = locManager.getBestProvider(criteria, true);
        boolean gps_enabled=locManager.isProviderEnabled(provider);
        if (gps_enabled == false) {
        	statusText.setText("Ative o GPS para continuar");
        	return;
        }
        
        btPontoRonda.setEnabled(false);
        btFinalizaRonda.setEnabled(true);
		
		/*
		statusText.setText("Vou chamar o teste Roy");
		
		double gpslat = 0, gpslon = 0;
		
        Criteria criteria = new Criteria();
        criteria.setAccuracy(Criteria.ACCURACY_FINE);
        LocationManager locManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);
        String provider = locManager.getBestProvider(criteria, true);

        Location location = locManager.getLastKnownLocation(provider);
        
        boolean gps_enabled=locManager.isProviderEnabled(provider);
        statusText.setText(provider + " is enabled " + gps_enabled);
        
        location = locManager.getLastKnownLocation(provider);
        gpslat = location.getLatitude();
        gpslon = location.getLongitude();
         
        edLatitude.setText(String.valueOf(gpslat));
        edLongitude.setText(String.valueOf(gpslon));
		*/
        
        // ********new AsyncOperaGPS().execute(statusText, edLatitude, edLongitude, locManager, rotaFeita);
        
        /*
		statusText.setText("Recolhendo informações do GPS em background");
		
        Intent GPSIntent = new Intent(this, ActivityOperaGPS.class);

        // GPSIntent.putExtra(EXTRA_ROTAFEITA, rotaFeita);
		
        PendingIntent callGPS = PendingIntent.getActivity(this, 0, GPSIntent, 0);
        
        AlarmManager am = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
        am.set(AlarmManager.RTC_WAKEUP, 3000, callGPS);        
         */
		
		// MARCELO
	      LocationManager lManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);
	      LocationListener lListener = new LocationListener() {
	          public void onLocationChanged(Location locat) {
	              updateView(locat);
	          }
	          public void onStatusChanged(String provider, int status, Bundle extras) {}
	          public void onProviderEnabled(String provider) {}
	          public void onProviderDisabled(String provider) {
	        	  statusText.setText("Ative o GPS para continuar");
	          }
	      };
	      lManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, lListener);
	      
	      task = new AsyncOperaGPS().execute(statusText, edLatitude, edLongitude, locManager, rotaFeita);
	}
	
	  public void updateView(Location locat){
		  Double dlon, dlat, a, distancia;
	      Double latitude = locat.getLatitude();
	      Double longitude = locat.getLongitude();  
	      dlon = Math.toRadians(longitudePto - longitude);  
	      dlat = Math.toRadians(latitudePto - latitude);  
	      a = Math.pow(Math.sin(dlat/2),2) + Math.cos(latitude) * Math.cos(latitudePto) * Math.pow(Math.sin(dlon/2),2);  
	      /*return 6378140 * distancia; /* 6378140 is the radius of the Earth in meters*/ 
	      
	      edLatitude.setText(latitude.toString());
	      edLongitude.setText(longitude.toString());
	      //statusText.setText("Agora deveria estar funcionando, vou enviar os dados");
	      // new AsyncEnviaDadosRonda().execute("http://multidot.com.br/mr/mr.php?usuario=teste&ronda=ronda_teste&long="+longitude+"&lat="+latitude+"&", statusText);
	  }
}


