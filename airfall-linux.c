#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <netinet/in.h>

char* get_lan_ip();

int main(){
	get_lan_ip();	
	
}

char* get_lan_ip(){
	struct ifaddrs *ifaddr, *ifa;
	getifaddrs(&ifaddr);
        char ip[INET_ADDRSTRLEN];

    	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) continue;

        if (ifa->ifa_addr->sa_family == AF_INET) {

            if (ifa->ifa_name[0] == 'w' && ifa->ifa_name[1] == 'l') {
                struct sockaddr_in *in = (struct sockaddr_in*)ifa->ifa_addr;
                inet_ntop(AF_INET, &in->sin_addr, ip, INET_ADDRSTRLEN);

                printf("IP (%s): %s\n", ifa->ifa_name, ip);
            }
        }
    }

}
