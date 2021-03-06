int core_last_update = 0;
int core_update_interval = 15;

void update_core() {
  if (wallclock-core_last_update < core_update_interval) { return; }
  core_last_update = wallclock;
  
  ping("","");
}

void ping(char *topic, char *message) {   
  DEBUG("PING message: %s\n", message, "","","");
  sprintf(buffer1, "%s%s/manager/%s/pong", prefix,suffix,MAC);
  DEBUG("PING publish: (%s)\n", buffer1, "","","");
  publish(buffer1, IP); 
  return;
}

void reboot(char *topic, char *message) {


}

void version(char *topic, char *message) {
  sprintf(buffer1, "%s/manager/%s/version", prefix,MAC);
  sprintf(buffer2, "%i.%i", VERSIONMAJOR, VERSIONMINOR);

  Serial.printf("VERSION: %s => %s", buffer1, buffer2);

  publish(buffer1, buffer2); 

}

void uptime(char *topic, char *message) {
  sprintf(buffer1, "%s/manager/%s/uptime", prefix,MAC);
  sprintf(buffer2, "%i", millis()/1000);

  DEBUG("UPTIME: %i", millis()/1000, "", "", "");

  publish(buffer1, buffer2); 
}



