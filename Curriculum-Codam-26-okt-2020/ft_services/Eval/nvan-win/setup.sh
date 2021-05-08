#!/bin/bash

BBGREEN='\033[1;92m'
RESET='\033[0m'

echo -e "${BBGREEN}Start minikube...${RESET}"

minikube --vm-driver=virtualbox start

# start minikube dashboard in detached mode
minikube dashboard &

echo -e "${BBGREEN}Enable addons...${RESET}"

minikube addons enable metallb
minikube addons enable metrics-server

kubectl apply -f ./srcs/metallb-config.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

kubectl create serviceaccount monitoring
kubectl apply -f srcs/serviceaccount.yaml

# point shell to minikube’s docker-daemon
eval $(minikube docker-env)

sleep 3

SVC_LIST="nginx mysql phpmyadmin wordpress ftps influxdb telegraf grafana"

echo -e "${BBGREEN}Deploy services${RESET}"

for SVC in $SVC_LIST
do
    echo -e "${BBGREEN}$SVC${RESET}"
	docker build -t $SVC ./srcs/$SVC
	kubectl apply -f ./srcs/$SVC.yaml
    sleep 2
done
