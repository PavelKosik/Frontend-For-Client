// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRegistrationUserWidget.h"
#include "MyHUD.h"

//makes LoginMenu appear
void UMyRegistrationUserWidget::OpenLoginMenu() {
	UGameplayStatics::GetPlayerController(this, 0)->GetHUD<AMyHUD>()->OpenLoginWidget();
}
