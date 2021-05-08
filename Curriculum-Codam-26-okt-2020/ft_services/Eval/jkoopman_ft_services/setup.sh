#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;92m'
CYAN='\033[0;36m'
NC='\033[0m'

# Sexy print function
print () {
	if [ $2 == 0 ]; then
		printf "[${CYAN}$1${NC}] Building\n"
	elif [ $2 == 1 ]; then
		printf "[${CYAN}$1${NC}] Applying yaml config\n"
	else
		printf "[${GREEN}$1${NC}] Finished setting up\n\n"
	fi
}

# Starting script
if minikube version &> /dev/null; then
	minikube stop
else
	printf "${RED}Minikube not found.${NC}\n"
	exit 1
fi

# Minikube setup
printf "\n${GREEN}Starting${NC} minikube\n\n"
minikube start --driver=virtualbox
minikube addons enable metallb
minikube addons enable dashboard
minikube addons enable metrics-server

# MetlaLB config
print "MetalLB" 0
printf "[${CYAN}MetalLB${NC}] Generating secret\n"
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
print "MetalLB" 1
printf "[${CYAN}MetalLB${NC}] Applying yaml config\n"
kubectl apply -f srcs/metallb.yaml
print "MetalLB" 2

# Run minikube VM
eval $(minikube docker-env)

# Serviceaccount
kubectl create serviceaccount admin
kubectl apply -f srcs/serviceaccount.yaml

# Services setup
SERVICE_LIST="nginx ftps mysql phpmyadmin wordpress influxdb telegraf grafana"

printf "\n${GREEN}Deploying services${NC}...\n\n"
for SERVICE in $SERVICE_LIST
do
	print "$SERVICE" 0
	docker build -t ft-$SERVICE ./srcs/$SERVICE
	print "$SERVICE" 1
	kubectl apply -f ./srcs/$SERVICE/$SERVICE.yaml
	print "$SERVICE" 2
done

# End Report
MINIKUBE_IP=$(minikube ip)

printf "Minikube IP: $MINIKUBE_IP\n"
printf "Phpmyadmin: mysql:mysql\n"
printf "Wordpress: admin:admin\n"
printf "Ftps: admin:admin\n"
printf "Ssh: admin:admin\n"
printf "Grafana: admin:admin\n"

sleep 5

kubectl get pods

kubectl get Services

minikube dashboard &