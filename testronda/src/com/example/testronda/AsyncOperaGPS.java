package com.example.testronda;

import android.content.Context;
import android.location.Criteria;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.AsyncTask;
import android.util.Log;
import android.widget.EditText;
import android.widget.TextView;
import com.example.testronda.Ponto;
import com.google.android.gms.location.LocationClient;

public class AsyncOperaGPS extends AsyncTask<Object, Void, Ponto> {

    private Exception exception;
	 TextView statusText;
	 TextView edLatitude;
	 TextView edLongitude;
	 LocationManager locManager;
	 ListaPontos rotaFeita;
	 Ponto pontoAtual;
	
    protected Ponto doInBackground(Object... urls) {
    	
    	String content = null;
    	
    	String provider = null;
    	statusText = (TextView) urls[0];
    	edLatitude = (TextView) urls[1];
    	edLongitude = (TextView) urls[2];
    	locManager = (LocationManager) urls[3];
    	rotaFeita = (ListaPontos) urls[4];
    	
    	boolean gps_enabled = false;
    	
        try {
    		Double gpslat = 99.9, gpslon = 88.8;
    		
            Criteria criteria = new Criteria();
            // criteria.setAccuracy(Criteria.ACCURACY_FINE);
            // LocationManager locManager = (LocationManager)getSystemService(Context.LOCATION_SERVICE);
             provider = locManager.getBestProvider(criteria, true);

            Location location = locManager.getLastKnownLocation(provider);
            
             gps_enabled = locManager.isProviderEnabled(provider);
            
            //location = locManager.getLastKnownLocation(provider);
            
             /*
             LocationClient mLocationClient = new LocationClient(
                     getApplicationContext(),
                     this,  // ConnectionCallbacks
                     this); // OnConnectionFailedListener
             String msg = "Location = " + mLocationClient.getLastLocation();
			*/
       
            //gpslat = location.getLatitude();
            //gpslon = location.getLongitude();
             
            while (true) { 
            	gpslat = Double.valueOf(edLatitude.getText().toString());
            	gpslon = Double.valueOf(edLongitude.getText().toString());
    	    
            	//pontoAtual = new Ponto(gpslat, gpslon);
            
            	new AsyncEnviaDadosRonda().execute("http://multidot.com.br/mr/mr.php?usuario=teste&ronda=ronda_teste&lon="+gpslon+"&lat="+gpslat+"&cp=n", statusText);
            	Thread.sleep(3000);
            }
        } catch (Exception e) {
        	content = "[OperaGPS] GPS exception " + e + " provider used " + provider ;
        	Log.e("AsyncOperaGPS", content);
        }
		// return content;
        return pontoAtual;
    }

    protected void onPostExecute(Ponto pontoAtual) {

    	if (pontoAtual != null) {
    		//rotaFeita.InserePonto(pontoAtual);
    		//edLatitude.setText(String.valueOf(pontoAtual.latitude));
    		//edLongitude.setText(String.valueOf(pontoAtual.longitude));
    		// statusText.setText("Numero de pontos: " + String.valueOf(rotaFeita.tamanhoLista()));
    		new AsyncEnviaDadosRonda().execute("http://multidot.com.br/mr/mr.php?usuario=teste&ronda=ronda_teste&long="+pontoAtual.longitude+"&lat="+pontoAtual.latitude+"&", statusText);
    	} else {
    		statusText.setText("Houve um problema");
    	}
    	// Save to the static location queue
    	
    }
    
    protected void onCancelled(Ponto pontoAtual) {
    	// Como não estamos mantendo em uma fila no momento, simplesmente voltar
    }
 }

