package main

import (
	"testing"

	"github.com/sclevine/agouti"
)

func TestServer(t *testing.T) {
	driver := agouti.PhantomJS()
	if err := driver.Start(); err != nil {
		t.Errorf("Failed to start driver: %v", err)
	}
	page, err := driver.NewPage()
	if err != nil {
		t.Errorf("Failed to open page: %v", err)
	}
	if err := page.Navigate("http://127.0.0.1:8080/check_this"); err != nil {
		t.Errorf("Failed to navigate to server: %v", err)
	}
	text, err := page.FindByClass(`text`).Text()
	if err != nil {
		t.Errorf("Failed to extract text: %v", err)
	}
	str := "You've just entered 'check_this'"
	if text != str {
		t.Errorf("Text mismatch, got: %v, want: %v", text, str)
	}
	if err := driver.Stop(); err != nil {
		t.Errorf("Failed to stop driver: %v", err)
	}
}
